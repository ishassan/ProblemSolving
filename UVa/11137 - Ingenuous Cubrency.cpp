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
#include <set>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int coins[21] = { 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728,
		2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261 };

ll memo[10002][21];

ll DP(int n, int idx) {
	if (n == 0)
		return 1;
	if (idx == 21 || n - coins[idx] < 0)
		return 0;

	ll& m = memo[n][idx];

	if (m != -1)
		return m;

	m = 0;
	m = DP(n, idx + 1);
	m += DP(n - coins[idx], idx);

	return m;
}
int main() {

	int n;
	memset(memo, -1, sizeof memo);
	while (scanf("%d", &n) != -1)
		printf("%lld\n", DP(n, 0));
	return 0;

}
