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
int match[23];
int input[23], seq[23];
int memo[23][23];

int DP(int cur, int last) {
	if (cur > n)
		return 0;

	if (last != -1 && memo[cur][last] != -1)
		return memo[cur][last];

	int c1 = DP(cur + 1, last);
	int c2 = 0;
	if (last == -1 || seq[cur] > seq[last])
		c2 = DP(cur + 1, cur) + 1;

	return memo[cur][last] = max(c1, c2);
}
int main() {

	cin >> n;
	foe(i,1,n)
		cin >> match[i];

	int num;
	while (cin >> num) {
		memset(memo, -1, sizeof memo);
		seq[match[1]] = num;
		foe(i,2,n)
			cin >> input[i], seq[match[i]] = input[i];

		cout << DP(1, -1) << endl;
	}

	return 0;
}
