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

int n;
const int MAX = 210;
int g[MAX][MAX];

bool vis[MAX];
int par[MAX], dist[MAX];
int OO = 1e8;

int getPath(int from, int to) {

	memset(par, -1, sizeof par);
	memset(vis, 0, sizeof vis);
	memset(dist, 0, sizeof dist);

	dist[from] = OO;
	for (int k = 0; k < n; k++) {

		int maxi = 0, nxt = -1;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && dist[i] > maxi)
				nxt = i, maxi = dist[i];

		if (nxt == to)
			return dist[to];

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

	int d = n;
	while (par[d] != -1) {
		g[par[d]][d] -= r, g[d][par[d]] += r;
		d = par[d];
	}
}

int maxFlow() {

	int totalFlow = 0, val = 0;
	while ((val = getPath(1, n)) != -1) {
		totalFlow += val;
		removePath(val);
	}
	return totalFlow;
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		memset(g, 0, sizeof g);
		scanf("%d", &n);
		int a, b;
		foo(i,1,n) {
			scanf("%d", &a);
			while (a--) {
				scanf("%d", &b);
				if (i == 1 || b==n)
					g[i][b] = 1;
				else
					g[i][b] = OO;
			}
		}

		printf("%d\n", maxFlow());
	}

	return 0;
}
