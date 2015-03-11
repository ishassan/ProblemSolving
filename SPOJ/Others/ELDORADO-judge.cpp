// Autor: Adrian Kuegel
// Date: 7. 7. 2008
// Complexity: O(n^3)
// Algorithm: Dynamic Programming

#include <stdio.h>
#include <limits.h>
#include <set>
using namespace std;

#define MAXN 128

int a[MAXN];
long long dp[MAXN][MAXN];

int main() {

	int n, k;
	while(scanf("%d %d", &n, &k) == 2 && (n > 0 || k > 0)) {

		long long ans = 0;
		set<int> have;
		for (int i=0; i<n; ++i) {
			scanf("%d", &a[i]);

			have.insert(a[i]);
			dp[i][0] = 1;
			for (int j=1; j<k; ++j) {
				dp[i][j] = 0;
				for (int ii=0; ii<i; ++ii) {
					if (a[ii] >= a[i])
						continue;

					dp[i][j] += dp[ii][j-1];
				}
			}

			ans += dp[i][k-1];
		}
		printf("%lld\n", ans);
	}

	return 0;
}
