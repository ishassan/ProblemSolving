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

int A[102][102], B[102][102], C[102][102];
int main() {

	int tst, n, s;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d", &n, &s);
		rep(i,n)
		rep(j,s)
				scanf("%d", &A[i][j]);
		rep(i,n)
		rep(j,s)
				scanf("%d", &B[i][j]);
		rep(i,n)
		rep(j,s)
				scanf("%d", &C[i][j]);

		ll res=0;
		rep(i,n){
			ll mx=0;
			rep(j,s)
				mx = max(mx, min(A[i][j], B[i][j]) * (ll) C[i][j]);
			res+=mx;
		}
		printf("%lld\n", res);
	}
	return 0;
}
