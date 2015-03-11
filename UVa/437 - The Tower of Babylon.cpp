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
#include <set>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

struct state {
	ll w, l, h;
};

state build(ll ww, ll L, ll hh) {
	state s = { ww, L, hh };
	return s;
}

int n;
map<pair<ll, ll> , ll> memo;
state comp[190];

ll DP(ll w, ll l) {
	if (memo.find(mp(w,l)) != memo.end())
		return memo[mp(w,l)];

	ll h = 0;
	fo(i,n) {
		if (comp[i].w < w && comp[i].l < l)
			h = max(h, DP(comp[i].w, comp[i].l) + comp[i].h);
	}
	memo[mp(w,l)] = h;
	return h;
}
int main() {
	int tst;
	int t = 1;
	while (cin >> tst && tst) {
		memo.clear();
		memset(comp, 0, sizeof comp);
		n = 0;
		ll arr[3];
		fo(i,tst) {
			cin >> arr[0] >> arr[1] >> arr[2];
			sort(arr, arr + 3);
			do {
				comp[n++] = (build(arr[0], arr[1], arr[2]));
			} while (next_permutation(arr, arr + 3));
		}

		ll res = 0;
		fo(i,n)
			res = max(res, DP(comp[i].w, comp[i].l) + comp[i].h);

		cout << "Case " << t++ << ": maximum height = " << res << "\n";
	}

	return 0;
}
