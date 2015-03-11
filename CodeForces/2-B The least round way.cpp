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
pii g[1002][1002];
int n;
int memo1[1002][1002];
int memo2[1002][1002];

pii fact(int t) {
	if (t == 0)
		return mp(1,1);

	int c2 = 0, c5 = 0;
	while (t % 2 == 0)
		t /= 2, c2++;
	while (t % 5 == 0)
		t /= 5, c5++;

	return mp(c2,c5);
}

int DP1(int i, int j) {
	if (i == n - 1 && j == n - 1)
		return g[i][j].first;

	if (memo1[i][j] != -1)
		return memo1[i][j];

	int c1 = 1 << 30, c2 = 1 << 30;

	if (i + 1 < n)
		c1 = DP1(i + 1, j), c1 += g[i][j].first;
	if (j + 1 < n)
		c2 = DP1(i, j + 1), c2 += g[i][j].first;

	return memo1[i][j] = min(c1, c2);
}

int DP2(int i, int j) {
	if (i == n - 1 && j == n - 1)
		return g[i][j].second;

	if (memo2[i][j] != -1)
		return memo2[i][j];

	int c1 = 1 << 30, c2 = 1 << 30;

	if (i + 1 < n)
		c1 = DP2(i + 1, j), c1 += g[i][j].second;
	if (j + 1 < n)
		c2 = DP2(i, j + 1), c2 += g[i][j].second;

	return memo2[i][j] = min(c1, c2);
}

void build1(int i, int j) {
	if (i == n - 1 && j == n - 1)
		return;

	int c1 = 1 << 30, c2 = 1 << 30;

	if (i + 1 < n)
		c1 = DP1(i + 1, j), c1 += g[i][j].first;
	if (j + 1 < n)
		c2 = DP1(i, j + 1), c2 += g[i][j].first;

	if (c1 < c2) {
		printf("D");
		build1(i + 1, j);
	} else {
		printf("R");
		build1(i, j + 1);
	}
}

void build2(int i, int j) {
	if (i == n - 1 && j == n - 1)
		return;

	int c1 = 1 << 30, c2 = 1 << 30;

	if (i + 1 < n)
		c1 = DP2(i + 1, j), c1 += g[i][j].second;
	if (j + 1 < n)
		c2 = DP2(i, j + 1), c2 += g[i][j].second;

	if (c1 < c2) {
		printf("D");
		build2(i + 1, j);
	} else {
		printf("R");
		build2(i, j + 1);
	}
}

void handle0(int zi, int zj) {
	printf("1\n");
	fo(i,zi)
		printf("D");
	fo(j,n-1)
		printf("R");
	foo(i,zi,n-1)
		printf("D");
}
int main() {

	int zi = -1, zj = -1;
	scanf("%d", &n);
	fo(i,n)
		fo(j,n) {
			scanf("%d", &g[i][j].first);
			if (g[i][j].first == 0)
				zi = i, zj = j;
			g[i][j] = fact(g[i][j].first);
		}

	memset(memo1, -1, sizeof memo1);
	memset(memo2, -1, sizeof memo2);
	int r1 = DP1(0, 0);
	int r2 = DP2(0, 0);

	if (zj > -1 && min(r1, r2) > 1) {
		handle0(zi, zj);
		return 0;
	}

	if (r1 < r2) {
		printf("%d\n", r1);
		build1(0, 0);
	} else {
		printf("%d\n", r2);
		build2(0, 0);
	}

	return 0;
}
