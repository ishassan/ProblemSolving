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

int n, src, dest;
int g[103][103];
bool vis[103];
int par[103], dist[103];

int getPath() {

	memset(par, -1, sizeof par);
	memset(vis, 0, sizeof vis);
	memset(dist, 0, sizeof dist);

	dist[src] = 1e9;
	for (int k = 1; k <= n; k++) {

		int maxi = 0, nxt = -1;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && dist[i] > maxi)
				nxt = i, maxi = dist[i];

		if (nxt == dest)
			return dist[dest];
		if (nxt == -1)
			return -1;

		vis[nxt] = 1;
		for (int i = 1; i <= n; i++) {
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

	int t = 1;
	while (scanf("%d", &n) != -1 && n) {
		int a, b, c, num;
		scanf("%d%d%d", &src, &dest, &num);
		memset(g, 0, sizeof g);

		fo(i,num) {
			scanf("%d%d%d", &a, &b, &c);
			g[a][b] += c;
			g[b][a] += c;
		}

		printf("Network %d\n", t++);
		printf("The bandwidth is %d.\n\n", maxFlow());

	}

	return 0;
}
