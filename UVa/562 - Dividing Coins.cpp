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

int n;
int sum, goal;
int coins[102];
int memo[102][50002];

int DP(int idx, int res) {
	if (res == goal)
		return sum % 2;

	if (res > goal)
		return abs(res - (sum - res));

	if (idx >= n)
		return abs(res - (sum - res));

	if (memo[idx][res] != -1)
		return memo[idx][res];

	int c1 = DP(idx + 1, res + coins[idx]);
	int c2 = DP(idx + 1, res);

	return memo[idx][res] = min(c1, c2);

}
int main() {

	int tst;
	cin >> tst;
	while (tst--) {
		memset(memo, -1, sizeof memo);
		sum = 0;
		cin >> n;
		fo(i,n)
			cin >> coins[i], sum += coins[i];
		goal = sum / 2;
		int r = DP(0, 0);
		cout << r << endl;
	}

	return 0;
}
