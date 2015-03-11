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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int arr[502][6];
int memo[502][6];
int n;

string mv[6] = { "front", "back", "left", "right", "top", "bottom" };

//0 -> 1, 1->0, 2->3, 3->2

int DP(int lst, int btmpos) {
	int& m = memo[lst][btmpos];
	if (m != -1)
		return m;

	int res = 1;
	foo(i,lst+1,n)
		fo(j,6)
			if (arr[i][j] == arr[lst][btmpos]) {
				int p = (j % 2) ? j - 1 : j + 1;
				res = max(res, DP(i, p) + 1);
			}

	return m = res;
}

void build(int lst, int btmpos) {

	int res = 1, l = -1, up, down;
	foo(i,lst+1,n)
		fo(j,6)
			if (arr[i][j] == arr[lst][btmpos]) {
				int p = (j % 2) ? j - 1 : j + 1;
				if (res < DP(i, p) + 1)
					res = DP(i, p) + 1, l = i, up = j, down = p;
			}

	if (l == -1)
		return;
	cout << l + 1 << " " << mv[up] << endl;
	build(l, down);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int t = 1;
	string e = "";
	while (scanf("%d", &n) != -1 && n) {
		cout << e, e = "\n";

		fo(i,n)
			fo(j,6)
				scanf("%d", &arr[i][j]);

		memset(memo, -1, sizeof memo);
		int res = -1, a, b;
		fo(i,n)
			fo(j,6)
				if (res < DP(i, j))
					res = DP(i, j), a = i, b = j;

		printf("Case #%d\n%d\n", t++, res);
		int p = (b % 2) ? b - 1 : b + 1;
		cout << a + 1 << " " << mv[p] << endl;
		build(a, b);
	}

	return 0;

}
