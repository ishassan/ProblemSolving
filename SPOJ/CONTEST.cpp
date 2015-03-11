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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

#define MAXN 100
#define MAXEDG (MAXN*MAXN - MAXN)
#define oo 99999999
struct minCostMaxFlowStruct {
	int nEdge, nNodes;
	int parent[MAXN], cost[MAXN], flow[MAXN];
	struct Edge {
		int from, to, cost, flow;
		Edge() {
		}
		Edge(int f, int t, int c, int fl) :
			from(f), to(t), cost(c), flow(fl) {
		}
	} edges[MAXEDG];
	void addEdge(int f, int t, int c, int fl) {
		edges[nEdge++] = Edge(f, t, c, fl);
		edges[nEdge++] = Edge(t, f, -c, 0);
	}
	void getPathBellman(int src, int sink) {
		fill(cost, cost + nNodes, oo);
		memset(flow, 0, sizeof(flow));
		flow[src] = oo;
		cost[src] = 0;
		for (int i = 0; i < nNodes; i++) {
			bool finished = true;
			for (int j = 0; j < nEdge; j++) {
				Edge& e = edges[j];
				if (cost[e.from] + e.cost < cost[e.to] && e.flow) {
					cost[e.to] = cost[e.from] + e.cost;
					finished = false;
					flow[e.to] = min(flow[e.from], e.flow);
					parent[e.to] = j;
				}
			}
			if (finished)
				break;
		}
	}
	pair<int, int> minCostMaxFlow(int src, int sink)// first->cost , second -> flow
	{
		if (src == sink)
			return make_pair(0, oo);
		int totc = 0, totf = 0;
		while (true) {
			getPathBellman(src, sink);
			if (!flow[sink])
				break;
			for (int cur = sink; cur != src; cur = edges[parent[cur]].from) {
				edges[parent[cur]].flow -= flow[sink];
				edges[parent[cur] ^ 1].flow += flow[sink];
			}
			totf += flow[sink];
			totc += cost[sink] * flow[sink];
		}
		return make_pair(totc, totf);
	}
} m1, m2;

int bright[5];
int soltime[12][5]; //[prob][man]=time
int main() {

	int n, m;
	int tst=1;
	while (scanf("%d%d", &m, &n) && (n || m)) {
		mem(soltime,0);
		m1.nEdge = 0, m1.nNodes = 2 + n + n * m;
		rep(i,m)
			scanf("%d", bright + i);
		rep(i,n) {
			m1.addEdge(n + n * m, i, 0, 1);
			int k;
			int s[12], t[12];
			scanf("%d", &k);
			rep(kk,k)
				scanf("%d%d", s + kk, t + kk);
			rep(mm,m)
				rep(kk,k) {
					if (kk + 1 == k && bright[mm] >= s[kk])
						soltime[i][mm] = t[kk];
					else if (bright[mm] >= s[kk] && bright[mm] < s[kk + 1]) {
						soltime[i][mm] = t[kk];
						break;
					}
				}
		}

		rep (i,n)
			rep(j,m)
				rep(k,n) {
					if (soltime[i][j])
						m1.addEdge(i, n + j * n + k, (k + 1) * soltime[i][j], 1);
				}

		rep(j,m)
			rep(k,n)
				m1.addEdge(n + j * n + k, n + n * m + 1, 0, 1);

		pii mincst = m1.minCostMaxFlow(n + n * m, n + n * m + 1);
		double avg = (double) mincst.first / n;
		printf("Case %d\n", tst++);
		printf("Average solution time = %.2lf\n", avg);

		vector<pair<int,pii> > res;
		rep(i,m1.nEdge){
			if(m1.edges[i].from >=n && m1.edges[i].from < (n+n*m) && m1.edges[i].to < n && m1.edges[i].flow){
				int prob = m1.edges[i].to;
				int man = (m1.edges[i].from-n) / n;
				int start = m1.edges[i].from % n;
				res.push_back(mp(man, mp(start,prob)));
			}
		}
		sort(all(res));
		pii sol[12];
		int st=0;
		int man=-1;
		for (int i = sz(res)-1; i>=0; --i)
		{
			if(man != res[i].first){
				man = res[i].first;
				st=0;
			}
			sol[res[i].second.second] = mp(man,st);
			st += soltime[res[i].second.second][man];
		}


		rep(i,n)
			printf("Problem %d is solved by member %d from %d to %d\n",i+1, sol[i].first+1, sol[i].second, sol[i].second + soltime[i][sol[i].first]);
		printf("\n");
	}
	return 0;
}
