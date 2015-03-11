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
#include <list>
#include <hash_map>

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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

int n, m;
struct edge {
	int src, dest, cst;
	edge(int s, int d, int c) {
		src = s, dest = d, cst = c;
	}
};

vector<edge> edges;
int dist[1005];
bool vis[1005];
bool bellman(int src) {
	fill(dist, dist + n + 2, 1e6);
	dist[src] = 0;
	rep(k,n) {
		bool relax = 0;
		rep(i,m) {
			if (dist[edges[i].src] + edges[i].cst < dist[edges[i].dest])
				dist[edges[i].dest] = dist[edges[i].src] + edges[i].cst, relax
						= 1;
			vis[edges[i].src] = vis[edges[i].dest] = 1;
		}
		if (!relax)
			return 1;
	}
	return 0;
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d", &n, &m);
		int src, dest, cst;
		edges.clear();
		mem(vis,0);
		set<int> nodes;
		rep(i,m) {
			scanf("%d%d%d", &src, &dest, &cst);
			edges.push_back(edge(src, dest, cst));
			nodes.insert(src);
			nodes.insert(dest);
		}

		repi(it,nodes) {
			if (!vis[*it]) {
				if (!bellman(*it)) {
					printf("possible\n");
					goto end;
				}

			}
		}
		printf("not possible\n");
		end: ;

	}
	return 0;
}
