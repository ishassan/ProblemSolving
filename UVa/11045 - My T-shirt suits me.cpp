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
const int MAX = 50;
int g[MAX][MAX];
bool vis[MAX];
int par[MAX], dist[MAX];

string shrt[] = { "XS", "S", "M", "L", "XL", "XXL" };
map<string, int> code;

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
		int nsh, m, am;
		memset(g, 0, sizeof g);
		code.clear();
		scanf("%d%d", &nsh, &m);

		n = m + 8;
		am = nsh / 6;

		foe(i,1,m)
			g[0][i] = 1;

		foo(i,1,7) {
			g[m + i][n - 1] = am;
			code[shrt[i - 1]] = m + i;
		}

		char a[5], b[5];
		foe(i,1,m) {
			scanf("%s%s", a, b);
			g[i][code[a]] = 1, g[i][code[b]] = 1;
		}

		src = 0, dest = n - 1;
		int res = maxFlow();
		if (res >= m)
			printf("YES\n");
		else
			printf("NO\n");


	}

	return 0;
}
