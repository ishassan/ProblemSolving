#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int n, e;
int Index[5005], instack[5005], lowLink[5005], ind;
stack<int> stk;
vector<vi> adjlst;
set<int> res, finalres;

void SCC(int idx) {
	Index[idx] = lowLink[idx] = ind++;
	stk.push(idx), instack[idx] = 1;
	rep(i,sz(adjlst[idx])) {
		int nxt = adjlst[idx][i];
		if (instack[nxt]) {
			lowLink[idx] = min(lowLink[idx], lowLink[nxt]);
			continue;
		}

		if (Index[nxt] > -1)
			continue;

		SCC(nxt);
		lowLink[idx] = min(lowLink[idx], lowLink[nxt]);
	}

	if (lowLink[idx] == Index[idx]) {
		while (stk.top() != idx) {
			res.insert(stk.top());
			instack[stk.top()] = 0;
			stk.pop();
		}
		res.insert(stk.top());
		instack[stk.top()] = 0;
		stk.pop();

		bool valid = 1;
		repi(it,res)
			rep(j, sz(adjlst[*it]))
				if (res.find(adjlst[*it][j]) == res.end()) {
					valid = 0;
					break;
				}
		if(valid)
			finalres.insert(all(res));
		res.clear();
	}
}
int main() {

	int a, b;
	while (scanf("%d%d", &n, &e) == 2 && n) {
		mem(Index,-1), mem(instack,0);
		adjlst.clear();
		adjlst.resize(n + 5);
		res.clear(), finalres.clear();
		ind = 0;
		rep(i,e) {
			scanf("%d%d", &a, &b);
			adjlst[a - 1].push_back(b - 1);
		}
		rep(i,n) {
			if (Index[i] == -1) {
				SCC(i);
			}
		}

		char* str = "";
		repi(it,finalres)
			printf("%s%d", str, (*it) + 1), str = " ";
		printf("\n");
	}

	return 0;
}
