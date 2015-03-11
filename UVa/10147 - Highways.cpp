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
pii pnts[800];

struct edge {
	int from, to;
	ll cst;
	edge() {
	}
	edge(int f, int t, ll c) {
		from = f, to = t, cst = c;
	}

	//	bool operator<(const edge& E) {
	//
	//	}
};

bool cmp(edge e1, edge e2) {
	if (e1.cst < e2.cst)
		return 1;
	if (e1.cst > e2.cst)
		return 0;
	if (e1.from < e2.from)
		return 1;
	if (e1.from > e2.from)
		return 0;
	return e1.to < e2.to;
}

vector<edge> edges;

ll Cost(int from, int to) {
	ll x = (pnts[from].first - pnts[to].first);
	x *= x;

	ll y = pnts[from].second - pnts[to].second;
	y *= y;

	return x + y;
}

ll costArr[800][800];

struct DisjointSet {
	int nComp;
	int parent[800], rank[800];
	DisjointSet(int n) {
		nComp = n;
		rep(i,n)
			parent[i] = i, rank[i] = 1;
	}

	int find(int node) {
		if (parent[node] == node)
			return node;
		return parent[node] = find(parent[node]);
	}

	bool join(int f, int t) {
		f = find(f), t = find(t);
		if (f == t)
			return 0;

		if (rank[f] < rank[t])
			parent[f] = t;
		else if (rank[f] < rank[f])
			parent[t] = f;
		else
			parent[f] = t, ++rank[t];
		return 1;
	}
};

int main() {

	int tst, a, b;
	scanf("%d", &tst);
	while (tst--) {
		edges.clear();
		rep(i,800)
			reps(j,1,800)
			costArr[i][j]=0;

		scanf("%d", &n);
		rep(i,n)
			scanf("%d%d", &pnts[i].first, &pnts[i].second);

		scanf("%d", &e);
		rep(i,e) {
			scanf("%d%d", &a, &b), --a, --b;
			edges.push_back(edge(a, b, 0));
			costArr[a][b] = costArr[b][a] = -1;
		}

		rep(i,n)
			reps(j,1,n)
				if (costArr[i][j] > -1) {
					costArr[i][j] = costArr[j][i] = Cost(i, j);
					edges.push_back(edge(i, j, costArr[i][j]));
				}

		DisjointSet ds(n);
		sort(all(edges), cmp);
		vector<pii> res;
		for (int i = 0; i < sz(edges); ++i) {
			if (ds.join(edges[i].from, edges[i].to)
					&& costArr[edges[i].from][edges[i].to] > -1)
				res.push_back(mp(edges[i].from, edges[i].to));
		}

		rep(i,sz(res)) {
			printf("%d %d\n", res[i].first+1, res[i].second+1);
		}
		if(!sz(res))
			printf("No new highways need\n");

		if (tst)
			printf("\n");
	}

	return 0;
}
