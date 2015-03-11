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

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int nxt(ll val) {
	rep(i,60) {
		if ((1LL << i) >= val)
			return i;
	}
	return -1;
}
int main() {

	ll g, t, a, d, knoc;
	while (scanf("%lld%lld%lld%lld", &g, &t, &a, &d)) {
		if (g == -1 && t == -1 && a == -1 && d == -1)
			return 0;

		ll res = ((t * (t - 1)) / 2) * g;
		knoc = nxt(a * g + d);
		res += (1LL << knoc);

		ll orig = ((t * (t - 1)) / 2) * g;
		orig += a * g + d;

		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", g, a, t, d, res-1, res - orig );
	}

	return 0;
}
