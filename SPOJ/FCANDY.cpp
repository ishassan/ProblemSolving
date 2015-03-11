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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int cnt[101], val[101];
int n;

int memo[101][402];
int DP(int idx, int diff) {
	if (idx == n)
		return diff;

	int &m = memo[idx][diff + 200];
	if (m != -1)
		return m;

	m = 1 << 30;

	for (int i = 0; i <= cnt[idx]; i++) {
		int d = diff + i * val[idx] - (cnt[idx] - i) * val[idx];
		if (d > 200 || d < -200)
			continue;
		m = min(m, abs(DP(idx + 1, d)) );
	}
	return m;
}

int main() {

	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	fo(i,n)
		scanf("%d%d", cnt + i, val + i);

	printf("%d\n",DP(0,0));
	return 0;
}

