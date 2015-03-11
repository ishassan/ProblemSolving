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

int n, k;
int arr[101];
ll memo[101][101];
ll DP(int idx, int len) {
	if (len == k)
			return 1;
	if (idx >= n)
		return 0;
	ll&m = memo[idx][len];
	if (m != -1)
		return m;

	m =0;
	reps(i,idx+1,n){
		if(arr[i] > arr[idx])
			m += DP(i, len+1);
	}
	return m;
}
int main() {
	while (scanf("%d%d", &n, &k) && (n || k)) {
		rep(i,n)
			scanf("%d", &arr[i]);
		mem(memo,-1);

		ll res =0;
		rep(i,n)
			res += DP(i,1);

		printf("%lld\n",res);
	}

	return 0;
}
