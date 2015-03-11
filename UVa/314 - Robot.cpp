#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>
#include <cmath>
#include <queue>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

int m, n;
bool graph[52][52], vis[52][52][4];
int si, sj, di, dj, dir;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
char ar[] = { 'e', 's', 'w', 'n' };

struct state {
	int i, j, dir;
	bool operator==(state& s) {
		return (i == s.i && j == s.j && dir == s.dir);
	}
};

bool valid(int i, int j, int dir) {
	if (i < 0 || j < 0 || i >= m || j >= n || j + 1 >= n || i + 1 >= m)
		return 0;

	if (graph[i][j] || graph[i][j + 1] || graph[i + 1][j]
			|| graph[i + 1][j + 1])
		return 0;

	return 1;
}
int BFS() {
	state src = { si, sj, dir }, dest = { di, dj, dir };
	queue<state> q;
	q.push(src);
	int lvl = 0;
	vis[si][sj][dir] = 1;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			src = q.front();
			q.pop();

			if (src.i == dest.i && src.j==dest.j)
				return lvl;

			state tmp = src;
			foe(i,1,3) {
				tmp.i += dr[tmp.dir];
				tmp.j += dc[tmp.dir];
				if (!valid(tmp.i, tmp.j, tmp.dir))
					break;

				if(vis[tmp.i][tmp.j][tmp.dir])
					continue;

				vis[tmp.i][tmp.j][tmp.dir] = 1;
				q.push(tmp);
			}

			tmp = src;
			for (int i = 1; i < 4; i += 2) {
				tmp.dir = (src.dir + i) % 4;
				if (!vis[tmp.i][tmp.j][tmp.dir])
					vis[tmp.i][tmp.j][tmp.dir] = 1, q.push(tmp);
			}

		}
		lvl++;
	}
	return -1;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	while (scanf("%d%d", &m, &n) != -1 && (m || n)) {
		fo(i,m)
			fo(j,n)
				scanf("%d", &graph[i][j]);

		char d[10];
		memset(vis, 0, sizeof vis);
		scanf("%d%d%d%d%s", &si, &sj, &di, &dj, d);
		si--, sj--, di--, dj--;

		fo(i,4)
			if (d[0] == ar[i])
				dir = i;

		printf("%d\n", BFS());

	}
	return 0;
}

