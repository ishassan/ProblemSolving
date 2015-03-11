#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)

int g[1010];
pair<int, int> accum[1010];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int T, n, k, r;
	scanf("%d", &T);

	foo(t,1,T+1) {
		printf("Case #%d: ", t);
		scanf("%d%d%d", &r, &k, &n);
		fo(i,n)
			scanf("%d", g + i);

		long long res = 0;
		int start = 0, rr = r;

		fo(nn,n) {
			accum[nn].first = 0;
			start = nn;
			for (int i = 0; i < n && accum[nn].first < k; i++) {
				accum[nn].first += g[start % n];
				if (accum[nn].first > k) {
					accum[nn].first -= g[start % n];
					break;
				}
				start++;
			}
			accum[nn].second = start%n;

		}

		start = 0, rr = r;
		while (rr--) {
			res += accum[start].first;
			start = accum[start].second;
		}
		printf("%lld\n", res);
	}
	return 0;
}
