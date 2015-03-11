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

const int SIZE = 1003;
int per, rel;
map<string, int> Map;
vector<vi> adjlst;
int lowLink[SIZE],Index[SIZE]; // Index array indicates the index that the node has entered in the stack, if 0->5, 5->3, 3->0 then index[0]=0 index[5]=1 index[3]=2, so i can minimize lowLink with the order of enter , not the node number, i dont' care about the node number or name
bool vis[SIZE], instack[SIZE];
stack<int> stk;

int res,ind;

void tarjan(int idx) {
	Index[idx] = lowLink[idx] = ind++;
	rep(i,sz(adjlst[idx])) {
		int nxt = adjlst[idx][i];
		if (vis[nxt] && !instack[nxt]) {
			continue;
		}
		if (instack[nxt]) {
			lowLink[idx] = min(lowLink[idx], lowLink[nxt]);
			continue;
		}
		vis[nxt] = 1;
		instack[nxt] = 1;
		stk.push(nxt);
		tarjan(nxt);
		lowLink[idx] = min(lowLink[idx], lowLink[nxt]);
	}

	if (lowLink[idx] == Index[idx]) {
		++res;
		while (stk.top() != idx)
		{
			instack[stk.top()] = 0;
			stk.pop();
		}
		instack[stk.top()] = 0;
		stk.pop();
	}
}
int main() {

	string str;
	while (scanf("%d%d", &per, &rel) && (per || rel)) {
		ind=0;
		mem(Index,0);
		getline(cin, str);
		while (stk.size())
			stk.pop();
		Map.clear();
		adjlst.clear();
		adjlst.resize(per + 3);
		mem(vis,0), mem(instack,0);
		res = 0;
		rep(i,per) {
			getline(cin, str);
			Map[str] = i;
		}

		rep(i,rel) {
			int f, t;
			getline(cin, str);
			f = Map[str];
			getline(cin, str);
			t = Map[str];

			adjlst[f].push_back(t);
		}

		rep(i,per) {
			if (!vis[i]) {
				vis[i] = 1;
				instack[i] = 1;
				stk.push(i);
				tarjan(i);
			}
		}

		printf("%d\n", res);
	}
	return 0;
}
