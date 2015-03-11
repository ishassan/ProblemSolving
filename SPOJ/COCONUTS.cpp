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

int src, dest;
const int MAX = 310;
int g[MAX][MAX];
vector<vector<int> > adjlst;
int par[MAX];

int getPath() {

	int dist[MAX] = { 0 }, vis[MAX] = { 0 };
	memset(par, -1, sizeof par);

	dist[src] = 1e6;
	priority_queue<pair<int, int> , vector<pair<int, int> > , less<pair<int,
			int> > > Q;
	Q.push(make_pair(1e6, src));
	while (!Q.empty()) {
		pair<int, int> S = Q.top();
		Q.pop();
		if (vis[S.second])
			continue;
		if (S.second == dest)
			return dist[S.second];
		vis[S.second] = 1;
		for (int i = 0; i < adjlst[S.second].size(); i++) {

			pair<int, int> j = mp(adjlst[S.second][i],
					g[S.second][adjlst[S.second][i]]);

			if (!vis[j.first] && min(dist[S.second], j.second) > dist[j.first]) {
				dist[j.first] = min(dist[S.second], j.second);
				par[j.first] = S.second;
				Q.push(make_pair(dist[j.first], j.first));
			}
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

	int n, m;
	while (scanf("%d%d", &n, &m) != -1 && (n || m)) {
		memset(g, 0, sizeof g);
		adjlst.clear();
		adjlst.resize(n + 2);

		int num, num2;
		src = 0, dest = n + 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &num);
			if (num)
				g[0][i] = 1, adjlst[0].push_back(i);
			else
				g[i][dest] = 1, adjlst[i].push_back(dest);
		}

		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &num, &num2);
			g[num][num2] = 1, adjlst[num].push_back(num2);
			g[num2][num] = 1, adjlst[num2].push_back(num);
		}

		printf("%d\n", maxFlow());
	}

	return 0;
}
