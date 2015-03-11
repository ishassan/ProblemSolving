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
#include <set>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int ki[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int kj[] = { 0, 0, 1, -1, -1, 1, -1, 1 };

int hi[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int hj[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

char grid[102][102];
bool vis[102][102];
int h, w;
int srci, srcj;

bool isSafe(int i, int j) {
	if (grid[i][j] == 'Z')
		return 0;
	fo(d,8) {
		int newr = i + hi[d];
		int newc = j + hj[d];

		if (newr < 0 || newc < 0 || newr >= h || newc >= w)
			continue;

		if (grid[newr][newc] == 'Z')
			return 0;
	}
	return 1;
}

int BFS() {
	queue<pair<int, int> > q;
	q.push(mp(srci,srcj));
	int lvl = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			srci = q.front().first;
			srcj = q.front().second;
			q.pop();

			if (grid[srci][srcj] == 'B')
				return lvl;

			fo(d,8) {
				int newr = srci + ki[d];
				int newc = srcj + kj[d];

				if (newr < 0 || newc < 0 || newr >= h || newc >= w)
					continue;

				if (vis[newr][newc])
					continue;

				if (grid[newr][newc] == 'B') {
					q.push(mp(newr,newc));
					continue;
				}

				if (!isSafe(newr, newc))
					continue;

				vis[newr][newc] = 1;
				q.push(mp(newr,newc));
			}
		}
		lvl++;
	}
	return -1;
}
int main() {

	int tst;
	cin >> tst;
	while (tst--) {
		memset(vis, 0, sizeof vis);
		cin >> h >> w;

		fo(i,h) {
			cin >> grid[i];
			fo(j,w)
				if (grid[i][j] == 'A')
					srci = i, srcj = j;
		}
		vis[srci][srcj] = 1;
		int r = BFS();
		if (r == -1)
			cout << "King Peter, you can't go now!\n";
		else
			cout << "Minimal possible length of a trip is " << r << endl;
	}

	return 0;
}

