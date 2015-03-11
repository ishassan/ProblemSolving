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
typedef long long ll;
using namespace std;

int n = 242, src = 0, dest = 241;
const int MAX = 250;
int g[MAX][MAX];
bool vis[MAX];
int par[MAX], dist[MAX];

int getPath() {

	memset(par, -1, sizeof par);
	memset(vis, 0, sizeof vis);
	memset(dist, 0, sizeof dist);

	dist[src] = 1e9;
	for (int k = 0; k < n; k++) {

		int maxi = 0, nxt = -1;
		for (int i = 0; i < n; i++)
			if (!vis[i] && dist[i] > maxi)
				nxt = i, maxi = dist[i];

		if (nxt == dest)
			return dist[dest];

		if (nxt == -1)
			return -1;

		vis[nxt] = 1;

		for (int i = 0; i < n; i++) {
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

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		int m, r, c;
		scanf("%d", &m);
		memset(g, 0, sizeof g);
		fo(i,m)
			scanf("%d%d", &r, &c), g[r + 1][c + 120 + 1] = 1;

		foe(i,1,120)
			g[0][i] = 1, g[i + 120][dest] = 1;

		printf("%d\n",maxFlow());
	}

	return 0;
}
