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

int n, m;
char graph[1002][1002];
int adjlst[1000000];
int Index[1000000], lowlink[1000000], compID[1000000];
bool instack[1000000];
stack<int> stk;
int ind = 0, ncomp = 0;
int toidx(int i, int j) {
	return i * m + j;
}

void tarjan(int idx) {
	Index[idx] = lowlink[idx] = ind++;
	instack[idx] = 1;
	stk.push(idx);
	int nxt = adjlst[idx];
	if (instack[nxt])
		lowlink[idx] = min(lowlink[idx], lowlink[nxt]);

	else if(Index[nxt]==-1){
		tarjan(nxt);
		lowlink[idx] = min(lowlink[idx], lowlink[nxt]);
	}

	if (lowlink[idx] == Index[idx]) {
		int tp;
		do {
			tp = stk.top();
			instack[tp] = 0;
			compID[tp]=ncomp;
			stk.pop();
		} while (tp != idx);
		++ncomp;
	}
}
int main() {
	mem(Index,-1);
	scanf("%d%d", &n, &m);
	rep(i,n) {
		scanf("%s", graph[i]);
		rep(j,m) {
			int cur = toidx(i, j);
			if (graph[i][j] == 'N')
				adjlst[cur] = toidx(i - 1, j);
			else if (graph[i][j] == 'S')
				adjlst[cur] = toidx(i + 1, j);
			else if (graph[i][j] == 'E')
				adjlst[cur] = toidx(i, j + 1);
			else
				adjlst[cur] = toidx(i, j - 1);
		}
	}
	int N = n * m;
	rep(i,N) {
		if (Index[i] == -1)
			tarjan(i);
	}

	vector<bool> hasout(ncomp);
	int res=0;
	rep(i,N){
		if(compID[i]!=compID[ adjlst[i] ])
			hasout[compID[i]]=1;
	}
	repi(it,hasout)
		res += (*it)==0;
	printf("%d\n", res);
	return 0;
}
