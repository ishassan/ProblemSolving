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

int r, c;
int grid[102][102];
int memo[102][102];

int di[] = { 0, 1, 0, -1 };
int dj[] = { -1, 0, 1, 0 };

int DP(int i, int j) {

	if (memo[i][j] != -1)
		return memo[i][j];

	int res = 1;
	for(int d=0; d<4; d++) {
		int newr = i + di[d];
		int newc = j + dj[d];

		if (newr < 0 || newc < 0 || newr >= r || newc >= c)
			continue;

		if (grid[newr][newc] >= grid[i][j])
			continue;

		res = max(res, DP(newr, newc) + 1);
	}

	return memo[i][j] = res;
}
int main() {

	int tst;
	cin >> tst;
	while (tst--) {
		memset(memo, -1, sizeof memo);
		string name;
		cin >> name >> r >> c;
		fo(i,r)
			fo(j,c)
				cin >> grid[i][j];

		int mx = -1;
		fo(i,r)
			fo(j,c)
				mx = max(mx, DP(i, j));

		cout << name << ": " << mx << endl;

	}
	return 0;
}
