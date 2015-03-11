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

int n;
int arr[1003][2];
int memo[1003][2];

int DP(int idx, bool prev){	//prev: 0->top segment is the first,1->top segment is the second
	if(idx >= n)
		return 0;

	int&m = memo[idx][prev];
	if(m != -1)
		return m;

	int c1 = DP(idx+1, 0) + arr[idx][0] + abs(arr[idx][1] - arr[idx-1][!prev]);
	int c2 = DP(idx+1, 1) + arr[idx][1] + abs(arr[idx][0] - arr[idx-1][!prev]);

	return m = max(c1,c2);
}
int main() {

	scanf("%d", &n);
	rep(i,n)
		scanf("%d%d", &arr[i][0], &arr[i][1]);

	mem(memo,-1);
	int res = max(DP(1, 0) + arr[0][0], DP(1, 1) + arr[0][1]);

	printf("%d\n",res);
	return 0;
}
