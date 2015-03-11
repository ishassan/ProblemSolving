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

int n[2];
int arr[2][10005];
int memo[2][10005];
bool vis[2][10005];

int DP(bool arri, int idx) {
	if (idx >= n[arri])
		return 0;

	if (vis[arri][idx]) //as the best summation may equal -1, so memset with -1 is not valid
		return memo[arri][idx];

	vis[arri][idx] = true;
	int c1 = DP(arri, idx + 1) + arr[arri][idx];
	int c2 = -1e9;
	int i = lower_bound(arr[!arri], arr[!arri] + n[!arri], arr[arri][idx])
			- arr[!arri];
	if (i < n[!arri] && arr[!arri][i] == arr[arri][idx])
		c2 = DP(!arri, i + 1) + arr[arri][idx];

	return memo[arri][idx] = max(c1, c2);
}
int main() {

	while (scanf("%d", &n[0]) && n[0]) {
		rep(i,n[0])
			scanf("%d", &arr[0][i]);

		scanf("%d", &n[1]);
		rep(i,n[1])
			scanf("%d", &arr[1][i]);

		mem(vis,0);
		int res = max(DP(0, 0), DP(1, 0));
		printf("%d\n", res);
	}
	return 0;
}
