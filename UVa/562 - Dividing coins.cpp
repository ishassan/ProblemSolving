#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[110];
int sum;
int c;
int memo[110][50010];
int DP(int idx, int val) {

	if (idx >= c) {
		int rest = sum - val;
		return abs(val - rest);
	}

	if (memo[idx][val] != -1)
		return memo[idx][val];

	int no = DP(idx + 1, val);
	int yes = DP(idx + 1, val + arr[idx]);

	return memo[idx][val] = min(no, yes);
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		memset(memo, -1, sizeof memo);
		scanf("%d", &c);
		sum = 0;
		for (int i = 0; i < c; ++i)
			scanf("%d", &arr[i]), sum += arr[i];
		cout << DP(0, 0) << endl;
	}

	return 0;
}
