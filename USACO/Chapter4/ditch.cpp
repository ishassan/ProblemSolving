/*
 ID: fci_isl1
 LANG: C++
 TASK:ditch
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
const int MAX = 300;
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

	if(vis[src])
		return 0;
	vis[src]=1;

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
int main() {

	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);

	scanf("%d%d", &m, &n);
	adjlst.resize(n + 4);
	rep(i,m) {
		int f, t, c;
		scanf("%d%d%d", &f, &t, &c);
		adjlst[f].push_back(edge(t, sz(adjlst[t]), c));
		adjlst[t].push_back(edge(f, sz(adjlst[f]) - 1, 0));
	}

	printf("%d\n", MaxFlow(1, n));

	return 0;
}
