#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string.h>

typedef long long ll;

using namespace std;

int main() {

	ll n;

	while (cin >> n) {

		n = (n + 4) / 5;
		ll area = 1LL << 62;
		ll bw = 1LL << 62, bh = 1LL << 62;

		for (ll w = 1; w <= n; w++) {

			ll h = (n + w - 1) / w;

			if (h < w)
				break;

			ll H = 44 * h + 4;
			ll W = 10 * w + 2;

			if (area > W * H || (area == W * H && (bh - bw) > (H - W))) {
				area = W * H, bh = H, bw = W;
			}

			 H = 44 * w + 4;
			 W = 10 * h + 2;

			if (area > W * H || (area == W * H && abs(bh - bw) > abs(H - W))) {
				area = W * H, bh = H, bw = W;
			}
		}

		if (bh < bw)
			swap(bh, bw);
		printf("%lld X %lld = %lld\n", bh, bw, area);
	}
	return 0;
}
