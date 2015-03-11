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

ll memo[30002][5];

int coins[] = { 1, 5, 10, 25, 50 };
int n;

ll DP(int res, int idx) {
	if (res == 0)
		return 1;

	if (res < 0 || idx > 4)
		return 0;

	if (memo[res][idx] != -1)
		return memo[res][idx];

	ll ret = DP(res - coins[idx], idx);
	ret += DP(res, idx + 1);

	return memo[res][idx] = ret;

}
int main() {

	memset(memo, -1, sizeof memo);
	while (cin >> n) {

		ll r = DP(n, 0);

		if (r == 1)
			cout << "There is only 1 way to produce " << n
					<< " cents change.\n";
		else
			cout << "There are " << r << " ways to produce " << n
					<< " cents change.\n";
	}

	return 0;
}
