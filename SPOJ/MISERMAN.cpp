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
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int h, w;

int arr[102][102];
int memo[102][102];

int DP(int i, int j) {
	if (i == h)
		return 0;

	int& m = memo[i][j];
	if (m != -1)
		return m;

	m = DP(i + 1, j) + arr[i][j];
	if (j - 1 >= 0)
		m = min(m, DP(i + 1, j - 1) + arr[i][j]);
	if (j + 1 < w)
		m = min(m, DP(i + 1, j + 1) + arr[i][j]);

	return m;
}
int main() {

	scanf("%d%d", &h, &w);
	rep(i,h)
		rep(j,w)
			scanf("%d", &arr[i][j]);

	int res = 1 << 30;
	rep(j,w) {
		mem(memo,-1);
		res = min(res, DP(0, j));
	}
	printf("%d\n", res);

	return 0;
}
