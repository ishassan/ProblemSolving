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

//#define fo(i,n) for(int i=0; i<n; i++)
//#define foo(i,m,n) for(int i=m; i<n; i++)
//#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

string s1, s2;
int sz1, sz2;
int memo[102][102];
int DP(int idx1, int idx2) {
	if (idx1 >= sz1 || idx2 >= sz2)
		return 0;
	if (memo[idx1][idx2] != -1)
		return memo[idx1][idx2];

	if (s1[idx1] == s2[idx2]) {
		return memo[idx1][idx2] = DP(idx1 + 1, idx2 + 1) + 1;
	}

	int c1 = DP(idx1 + 1, idx2);
	int c2 = DP(idx1, idx2 + 1);

	return memo[idx1][idx2] = max(c1, c2);

}
int main() {

	int tst = 1;
	while (1) {
		memset(memo, -1, sizeof memo);
		getline(cin, s1);
		if (s1 == "#")
			return 0;

		getline(cin, s2);

		sz1 = s1.size();
		sz2 = s2.size();
		int r = DP(0, 0);
		printf("Case #%d: you can visit at most %d cities.\n", tst++, r);
	}

	return 0;
}
