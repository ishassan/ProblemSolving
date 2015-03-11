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

int r, c, nmaze;
char g[20][30][30];
bool vis[20][30][30];

int di[5] = {0, 1, -1, 0, 0 };
int dj[5] = {0, 0, 0, 1, -1 };

struct state {
	int i, j, curMaze;
	state(int ii, int jj, int cur) {
		i = ii;
		j = jj;
		curMaze = cur;
	}
};

int BFS() {

	mem(vis,0);
	queue<state> q;
	q.push(state(0, 0, 0));
	vis[0][0][0] = true;

	int steps = 0;
	while (q.size()) {
		int siz = q.size();
		while (siz--) {
			state cur = q.front();
			q.pop();

			if (cur.i == r - 1 && cur.j == c - 1)
				return steps;

			int nxtMaze = (cur.curMaze + 1) % nmaze;

			rep(d,4) {
				int ni = cur.i + di[d];
				int nj = cur.j + dj[d];

				if (ni < 0 || nj < 0 || ni >= r || nj >= c)
					continue;

				if (vis[nxtMaze][ni][nj] || g[nxtMaze][ni][nj] == '1')
					continue;

				vis[nxtMaze][ni][nj] = 1;
				q.push(state(ni, nj, nxtMaze));
			}
		}
		++steps;
	}

	return -1;
}
int main() {

	int tst = 1;
	while (scanf("%d%d%d", &r, &c, &nmaze) && (r || c || nmaze)) {
		rep(i,nmaze) {
			rep(j,r) {
				scanf("%s", g[i][j]);
			}
		}

		int res = BFS();
		if (res > -1)
			printf("Case %d: Luke and Leia can escape in %d steps.\n", tst++,
					res);
		else
			printf("Case %d: Luke and Leia cannot escape.\n", tst++);
	}

	return 0;
}


