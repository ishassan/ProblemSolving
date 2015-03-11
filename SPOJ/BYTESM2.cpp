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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define scn(a,b) scanf(a,&b)
typedef long long ll;
using namespace std;

int h, w;
int arr[102][102];
int memo[102][102];
int DP(int i, int j) {
	if (i == h)
		return 0;
	int&m = memo[i][j];
	if (m != -1)
		return m;

	int c1 = 0, c2 = 0, c3 = 0;
	if (j > 0)
		c1 = DP(i + 1, j - 1);

	if (j + 1 < w)
		c3 = DP(i + 1, j + 1);

	c2 = DP(i + 1, j);

	return m = max(c1, max(c2, c3)) + arr[i][j];
}
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		memset(memo,-1,sizeof memo);
		scanf("%d%d", &h, &w);
		fo(i,h)
			fo(j,w)
				scanf("%d", &arr[i][j]);

		int mx = 0;
		fo(i,w)
			mx = max(mx, DP(0, i));
		printf("%d\n", mx);
	}
	return 0;
}
