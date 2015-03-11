#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[51];
int len[51][51];
int memo[51][51];

int DP(int s, int e, int l) {
	if (e - s <= 1)
		return 0;

	int &m = memo[s][e];
	if (m != -1)
		return m;

	int best = 2000000000, val;
	for (int i = s + 1; i < e; ++i) {
		val = DP(s, i, len[s][i]) + DP(i, e, len[i][e]) + l;

		best = min(best, val);
	}

	return m = best;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int l, n;
	while (scanf("%d", &l)) {
		if (l == 0)
			return 0;

		memset(arr, 0, sizeof arr);
		memset(len, 0, sizeof len);
		memset(memo, -1, sizeof memo);

		scanf("%d", &n);

		int a, b = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			arr[i] = a - b, b = a;
		}

		arr[n++] = l - b;

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j <= n; ++j)
				for (int k = i; k < j; ++k)
					len[i][j] += arr[k];

		printf("The minimum cutting is %d.\n", DP(0,n,l));

	}
	return 0;

}
