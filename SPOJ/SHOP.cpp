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
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int w, h;

char grid[30][30];
vector<pii> g[900];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int OO = 1000000; //just big number
int Dijkstra(int n, int src, int dest) {
	vector<int> vis(n, 0), dist(n, OO);
	dist[src] = 0; // we can reach source in no cost

	for (int t = 0; t < n; ++t) {
		int val = OO, idx = -1;
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && dist[i] < val)
				val = dist[i], idx = i;
		}

		if(idx==dest)
			return dist[dest];

		vis[idx] = 1; // 2) MARK as visited

		for (int i = 0; i < sz(g[idx]); ++i)
			if (dist[g[idx][i].first] > (val = dist[idx] + g[idx][i].second))
				dist[g[idx][i].first] = val;
	}
	return dist[dest];
}

int main() {

	while (scanf("%d%d", &w, &h) != -1 && (w || h)) {
		rep(i,900)
			g[i].clear();

		rep(i,h)
			scanf("%s", grid[i]);

		int src, dest;
		rep(i,h)
			rep(j,w) {
				if (grid[i][j] == 'X')
					continue;

				if (grid[i][j] == 'S')
					src = i * w + j;

				if (grid[i][j] == 'D')
					dest = i * w + j;

				rep(d,4) {
					int newr = i + di[d];
					int newc = j + dj[d];

					if (newr < 0 || newc < 0 || newr >= h || newc >= w)
						continue;

					if (grid[newr][newc] == 'S' || grid[newr][newc] == 'X')
						g[i * w + j].push_back(mp(newr * w + newc, OO));

					else if (grid[newr][newc] == 'D')
						g[i * w + j].push_back(mp(newr * w + newc, 0));

					else
						g[i * w + j].push_back(
								mp(newr * w + newc, grid[newr][newc]-'0'));
				}
			}

		printf("%d\n", Dijkstra(w * h, src, dest));

	}

	return 0;
}
