#include<iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int N, n, nums[250], dp[250][250][250], md = 10000007;

int calc(int i, int j, int k) {
	if (k == n)
		return 1;
	if (dp[i][j][k] != -1)
		return dp[i][j][k];
	int ret = calc(i, j, k + 1);
	if (nums[j] - nums[i] == nums[k] - nums[j])
		ret = (ret + calc(j, k, k + 1)) % md;
	return dp[i][j][k] = ret;
}

int main() {
	scanf("%d", &N);
	for (int nn = 1; nn <= N; nn++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		memset(dp, -1, sizeof dp);
		int ret = n;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				ret = (ret + calc(i, j, j + 1)) % md;
		printf("Case %d: %d\n", nn, ret);
	}
	return 0;
}
