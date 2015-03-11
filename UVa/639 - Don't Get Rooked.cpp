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

int n;
char g[4][4];
int vis[4][4];

void mark(int i, int j, int m) {
	foo(ii,i,n) {
		vis[ii][j] += m;
		if (g[ii][j] == 'X')
			break;
	}

	for (int ii = i-1; ii >= 0; ii--) {
		vis[ii][j] += m;
		if (g[ii][j] == 'X')
			break;
	}

	foo(jj,j+1,n) {
		vis[i][jj] += m;
		if (g[i][jj] == 'X')
			break;
	}

	for (int jj = j-1; jj >= 0; jj--) {
		vis[i][jj] += m;
		if (g[i][jj] == 'X')
			break;
	}
}

pii next(int i, int j) {
	foo(ii,i,n) {
		int pos = (ii == i) ? j + 1 : 0;
		foo(jj,pos,n) {
			if (vis[ii][jj] || g[ii][jj] == 'X')
				continue;
			return mp(ii,jj);
		}
	}
	return mp(n,n);
}

int rec(int i, int j) {
	if (i == n || j == n)
		return 0;
	pii p = next(i, j);
	int c1 = rec(p.first, p.second);
	int c2 = 1;
	mark(i, j, 1);
	p = next(i, j);
	c2 += rec(p.first, p.second);
	mark(i, j, -1);

	return max(c1, c2);

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	memset(vis, 0, sizeof vis);
	while (cin >> n && n) {
		fo(i,n)
			cin >> g[i];

		pii p = next(0, -1);
		cout << rec(p.first, p.second) << endl;
	}

	return 0;
}

