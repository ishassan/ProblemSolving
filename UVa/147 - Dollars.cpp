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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef unsigned long long ll;
using namespace std;

int mon[11] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5 };
ll memo[11][30002];

ll DP(int idx, int n) {
	if (n == 0)
		return 1;

	if (memo[idx][n] != -1)
		return memo[idx][n];

	ll res = 0;
	foo(i,idx,11)
		if (n - mon[i] >= 0)
			res += DP(i, n - mon[i]);

	return memo[idx][n] = res;
}
int main() {

	int n;
	int dec, frac;
	memset(memo, -1, sizeof memo);
	while (scanf("%d.%d", &dec, &frac) != -1) {
		n = dec * 100 + frac;
		if (n == 0)
			return 0;
		printf("%6.2f%17llu\n", (float)n/100, DP(0, n));
	}

	return 0;
}
