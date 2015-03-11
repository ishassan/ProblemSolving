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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pdd pair<double,double>
typedef long long ll;
using namespace std;

int n, m, s, v;
const int MAX = 303;
pdd gopher[MAX], holes[MAX];
int g[MAX][MAX];

int src, dest;
bool vis[MAX];
int par[MAX], dist[MAX];

int getPath() {

	memset(par, -1, sizeof par);
	memset(vis, 0, sizeof vis);
	memset(dist, 0, sizeof dist);

	dist[src] = 1e9;
	for (int k = 0; k <= dest; k++) {

		int maxi = 0, nxt = -1;
		for (int i = 0; i <= dest; i++)
			if (!vis[i] && dist[i] > maxi)
				nxt = i, maxi = dist[i];

		if (nxt == dest)
			return dist[dest];

		if (nxt == -1)
			return -1;

		vis[nxt] = 1;

		for (int i = 0; i <= dest; i++) {
			if (dist[i] < min(dist[nxt], g[nxt][i]))
				dist[i] = min(dist[nxt], g[nxt][i]), par[i] = nxt;
		}
	}
	return -1;
}

void removePath(int r) {

	int d = dest;
	while (par[d] != -1) {
		g[par[d]][d] -= r, g[d][par[d]] += r;
		d = par[d];
	}
}

int maxFlow() {

	int totalFlow = 0, val = 0;
	while ((val = getPath()) != -1) {
		totalFlow += val;
		removePath(val);
	}
	return totalFlow;
}

int main() {

	while (scanf("%d%d%d%d", &n, &m, &s, &v) != -1) {
		memset(g, 0, sizeof g);
		m += n;
		foe(i,1,n)
			scanf("%lf%lf", &gopher[i].first, &gopher[i].second);

		foe(i,n+1,m)
			scanf("%lf%lf", &holes[i].first, &holes[i].second);

		foe(i,1,n)
			foe(j,n+1,m) {
				double d = hypot(abs(gopher[i].first - holes[j].first), abs(
						gopher[i].second - holes[j].second));

				double t = d / v;
				if (t < (double) s || abs(t - s) < 1e-9)
					g[i][j] = 1;
			}

		src = 0, dest = m + 1;
		foe(i,1,n)
			g[src][i] = 1;
		foe(i,n+1,m)
			g[i][dest] = 1;

		printf("%d\n", n - maxFlow());
	}
	return 0;
}
