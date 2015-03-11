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
#include <list>
#include <climits>
#include <assert.h>
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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int c, d;
pii arr[204];

bool istrue(double T) {
	double prev = arr[0].first - T - d;
	rep(i,c) {
		int pnt = arr[i].first;
		int num = arr[i].second;

		while (num--) {
			double cur = max(prev + d, pnt - T);
			if(cur > pnt + T) return false;
			prev = cur;
		}
	}
	return true;
}
int main() {

	int tst;
	scanf("%d", &tst);
	repe(t,1,tst) {
		scanf("%d%d", &c, &d);
		rep(i,c)
			scanf("%d%d", &arr[i].first, &arr[i].second);

		double s = 0, e = 1e13;
		double res = 0;
		rep(i,100) {
			double mid = (s + e) / 2.0;
			if (istrue(mid)) {
				res = mid;
				e = mid;
			} else
				s = mid;
		}
		printf("Case #%d: %lf\n", t, res);

	}
	return 0;
}

