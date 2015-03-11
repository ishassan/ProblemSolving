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
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int arr[10002];
int n, k;
bool istrue(double val) {
	double res = 0;
	rep(i,n) {
		if (arr[i] > val) {
			double exceed = arr[i] - val;
			exceed -= (k * exceed) / 100.0;
			res += exceed;
		}
		else
			res -= val - arr[i];
	}

	return res < 1e-6;
}
int main() {

	scanf("%d%d", &n, &k);

	double mn = 1e9, mx = -1;
	rep(i,n) {
		scanf("%d", arr + i);
		mn = min(mn, (double)arr[i]);
		mx = max(mx, (double)arr[i]);
	}

	double ans;
	for (int bs = 0; bs < 100; ++bs) {
		double mid = mn + (mx - mn) / 2.0;
		if (istrue(mid))
			ans = mx = mid;
		else
			mn = mid;
	}

	printf("%.9lf\n", ans+1e-6);
	return 0;
}
