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
const int MAX = 300;
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

	//freopen("in.txt","r",stdin);
	string str;
	n = 38, src = 0, dest = 37;
	while (cin.good()) {
		memset(g, 0, sizeof g);
		int res = 0;
		while (getline(cin, str) && str != "") {

			int from = str[0] - 'A' + 1;
			int flow = atoi(str.c_str() + 1);
			g[src][from] = flow, res += flow;

			int i = 1;
			while (str[i++] != ' ')
				;
			for (; str[i] != ';'; i++)
				g[from][str[i] - 21] = 1;

		}
		foo(i,27,dest)
			g[i][dest] = 1;

		if (maxFlow() < res) {
			cout << "!\n";
			continue;
		}

		char path[15] = { 0 };

		foo(i,27,dest) {
			foo(j,1,27) {
				if (g[i][j] > 0)
					path[i - 27] = j - 1 + 'A';
			}
			if (path[i - 27] == 0)
				path[i - 27] = '_';
		}
		cout << path << endl;

	}
	return 0;
}
