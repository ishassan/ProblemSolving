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
typedef long long ll;
using namespace std;

int h, w;
char grid[100][100];
bool vis[100][100][16];

int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

struct state {
	char i, j;
	char clr;
};

void setColor(char &n, char clr) {
	if (clr == 'b')
		n |= 1;
	else if (clr == 'y')
		n |= 2;
	else if (clr == 'r')
		n |= 4;
	else if (clr == 'g')
		n |= 8;
}

bool getColor(char n, char clr) {
	if (clr == 'b')
		return (n & 1);

	else if (clr == 'y')
		return (n & 2);

	else if (clr == 'r')
		return (n & 4);

	else if (clr == 'g')
		return (n & 8);
	return 0;
}

int srci, srcj;
int BFS() {
	state cur = { srci, srcj, 0 };
	queue<state> q;
	q.push(cur);
	int lvl = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			cur = q.front();
			q.pop();

			if (grid[cur.i][cur.j] == 'X')
				return lvl;

			fo(d,4) {
				int newr = cur.i + di[d];
				int newc = cur.j + dj[d];

				if (newr < 0 || newc < 0 || newr >= h || newc >= w)
					continue;

				char g = grid[newr][newc];
				if (g == '#')
					continue;

				if ((g == 'B' || g == 'Y' || g == 'R' || g == 'G')
						&& !getColor(cur.clr, tolower(g)))
					continue;

				state tmp = {newr,newc,cur.clr};
				if(g=='b' || g=='y' || g=='r' || g=='g')
					setColor(tmp.clr,g);

				if(vis[newr][newc][tmp.clr])
					continue;

				vis[newr][newc][tmp.clr]=1;
				q.push(tmp);

			}
		}
		lvl++;
	}
	return -1;
}
int main() {

	while (cin >> h >> w && h && w) {
		memset(vis, 0, sizeof vis);

		fo(i,h)
			cin >> grid[i];

		fo(i,h)
			fo(j,w)
				if (grid[i][j] == '*') {
					srci = i, srcj = j;
					break;
				}

		vis[srci][srcj][0] = 1;
		int r = BFS();
		if (r == -1)
			cout << "The poor student is trapped!\n";
		else
			cout << "Escape possible in " << r << " steps.\n";
	}

	return 0;
}
