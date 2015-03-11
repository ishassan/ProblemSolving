/*
 ID: fci_isl1
 LANG: C++
 TASK:stall4
 */
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
#include <climits>

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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int m, n;
const int MAX = 500;
pii par[MAX];
bool vis[MAX];
struct edge {
	int to, revId, cst;
	edge(int t, int r, int c) :
		to(t), revId(r), cst(c) {
	}

};

vector<vector<edge> > adjlst;

int pathMin;
bool getPath(int src, int dest) {

	if (src == dest)
		return 1;

	if (vis[src])
		return 0;
	vis[src] = 1;

	rep(i, sz(adjlst[src])) {
		edge e = adjlst[src][i];
		if (par[e.to].first == -1 && e.cst > 0 && getPath(e.to, dest)) {
			pathMin = min(pathMin, e.cst);
			par[e.to] = mp(src,i);
			return true;
		}
	}

	return false;
}

void updatePath(int src, int dest) {
	if (src == dest)
		return;
	int fr = par[dest].first, idx = par[dest].second;
	int rev = adjlst[fr][idx].revId;
	adjlst[fr][idx].cst -= pathMin;
	adjlst[dest][rev].cst += pathMin;
	updatePath(src, fr);
}
int MaxFlow(int src, int dest) {
	int res = 0;
	do {
		mem(vis,0);
		mem(par,-1);
		pathMin = INT_MAX;
		if (!getPath(src, dest))
			break;
		res += pathMin;
		updatePath(src, dest);
	} while (true);
	return res;
}

inline void addEdge(int src, int dest, int cst) {
	adjlst[src].push_back(edge(dest, adjlst[dest].size(), cst));
	adjlst[dest].push_back(edge(src, adjlst[src].size() - 1, 0));
}
int main() {

	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);

	scanf("%d%d", &n, &m);
	adjlst.resize(n + m + 2);

	repe(i,n+1,n+m)
		addEdge(i, n + m + 1, 1);

	repe(i,1,n) {
		int num, to;
		scanf("%d", &num);
		addEdge(0, i, 1);
		while (num--) {
			scanf("%d", &to);
			addEdge(i, n + to, 1);

		}
	}

	printf("%d\n", MaxFlow(0, n + m + 1));
	return 0;
}
