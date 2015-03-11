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
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int r, c, srci, srcj;
char g[30][30];
int cst[30][30][30][30];
bool vis[30][30];
bool BFS(pii src, set<pii> dest) {
	mem(vis,0);
	queue<pii> q;
	q.push(src);
	vis[src.first][src.second] = true;
	int steps = 0;

	while (q.size()) {
		int siz = q.size();
		while (siz--) {
			pii cur = q.front();
			q.pop();

			if (dest.find(cur) != dest.end()) {
				dest.erase(cur);
				cst[src.first][src.second][cur.first][cur.second] = steps;
				cst[cur.first][cur.second][src.first][src.second] = steps;
			}
			if (sz(dest) == 0)
				return true;

			rep(d,4) {
				int ni = cur.first + di[d];
				int nj = cur.second + dj[d];

				if (ni < 0 || nj < 0 || ni >= r || nj >= c)
					continue;

				if (vis[ni][nj] || g[ni][nj] == 'x')
					continue;

				vis[ni][nj] = true;
				q.push(mp(ni,nj));
			}
		}
		++steps;
	}

	return false;
}

int calc(vector<pii>& v) {
	int res = cst[srci][srcj][v.front().first][v.front().second];
	reps(i,1,sz(v))
		res += cst[v[i - 1].first][v[i - 1].second][v[i].first][v[i].second];

	return res;
}
int main() {

	while (scanf("%d%d", &c, &r) && (c || r)) {
		vector<pii> tiles;
		srci = -1, srcj = -1;


		rep(i,r) {
			scanf("%s", g[i]);
			rep(j,c) {
				if (g[i][j] == 'o')
					srci = i, srcj = j;

				else if (g[i][j] == '*')
					tiles.push_back(mp(i,j));
			}
		}

		if (srci == -1) {
			printf("-1\n");
			continue;
		}

		int mn = 1e9;
		rep(i,sz(tiles)) {
			int si = (i == 0) ? srci : tiles[i - 1].first;
			int sj = (i == 0) ? srcj : tiles[i - 1].second;
			bool pass = BFS(mp(si,sj),
					set<pii> (tiles.begin() + i, tiles.end()));
			if (!pass)
				goto fail;
		}

		sort(all(tiles));
		do {
			mn = min(mn, calc(tiles));
		} while (next_permutation(all(tiles)));

		printf("%d\n", mn);
		continue;

		fail: printf("-1\n");
	}

	return 0;
}

