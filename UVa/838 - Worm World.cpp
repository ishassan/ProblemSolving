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
int n;
int grid[13][13];

int di[] = { 0, 1, 0, -1 };
int dj[] = { -1, 0, 1, 0 };

bool vis[1001];
int distinct, bst;
bool b = false;
void DFS(int i, int j, int cost) {

	bst = max(bst, cost);
	if (cost == distinct) {
		return;
	}

	for (int d = 0; d < 4; d++) {
		int newr = i + di[d];
		int newc = j + dj[d];

		if (newr < 0 || newc < 0 || newr >= n || newc >= n)
			continue;

		if (vis[grid[newr][newc]])
			continue;

		vis[grid[newr][newc]] = 1;
		DFS(newr, newc, cost + 1);
		if (bst == distinct) {
			return;
		}
		vis[grid[newr][newc]] = 0;

	}
}
int main() {

	int tst;
	cin >> tst;
	string end = "";
	while (tst--) {
		cout << end;
		end = "\n";
		cin >> n;
		distinct = 0, bst = 0;
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				if (!vis[grid[i][j]])
					vis[grid[i][j]] = 1, distinct++;
			}
		}
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++) {
			if (bst == distinct)
				break;
			for (int j = 0; j < n; j++) {

				vis[grid[i][j]] = 1;
				DFS(i, j, 1);
				vis[grid[i][j]] = 0;
				if (bst == distinct)
					break;
			}
		}
		cout << bst<< endl;
	}

	return 0;
}

