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
#include <numeric>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

int arr1[10010], arr2[10010];
int sz1, sz2;

long long memo[10010][2];
long long DP(int i, bool one) {
	if (one && i >= sz1)
		return 0;
	if (!one && i >= sz2)
		return 0;

	long long &m = memo[i][one];
	if (m != -1)
		return m;

	long long c1 = -(1LL << 62), c2 = -(1LL << 62);

	long long res = -(1LL << 62);
	if (one) {
		for (int j = 0; j < sz2; j++) {
			if (arr1[i] == arr2[j]) {
				c1 = DP(i + 1, one) + arr1[i];
				c2 = DP(j + 1, !one) + arr1[i];
				res = max(res, max(c1, c2));
			}
		}
		c1 = DP(i + 1, one) + arr1[i];
		res = max(res, c1);
	} else {
		for (int j = 0; j < sz1; j++) {
			if (arr2[i] == arr1[j]) {
				c1 = DP(i + 1, one) + arr2[i];
				c2 = DP(j + 1, !one) + arr2[i];
				res = max(res, max(c1, c2));
			}
		}
		c1 = DP(i + 1, one) + arr2[i];
		res = max(res, c1);
	}

	return m = res;

}
int main() {


	while (cin >> sz1) {
		if (sz1 == 0)
			return 0;

		fo(i,sz1)
			cin >> arr1[i];

		cin >> sz2;
		fo(i,sz2)
			cin >> arr2[i];


		memset(memo, -1, sizeof memo);
		long long r1 = DP(0, 1);
		memset(memo, -1, sizeof memo);
		long long r2 = DP(0, 0);
		cout << max(r1, r2) << endl;

	}
	return 0;
}

