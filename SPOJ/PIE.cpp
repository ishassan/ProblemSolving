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

int radii[10010];
int rmax = 10000;
int n, f;

bool isok(double size) {
	int cnt = 0;
	rep(i, n) {
		cnt += (int) ((radii[i] * radii[i] * M_PI) / size);
	}

	return (cnt >= f);
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {

		scanf("%d%d", &n, &f);
		++f;

		rep(i,n)
			scanf("%d", radii + i);


		double lo = 0, hi = M_PI * rmax * rmax;
		double szbst = 0;
		for (int bs = 0; bs < 50; bs++) {
			double mid = lo + ((hi - lo) / 2);
			if (isok(mid)) {
				szbst = mid;
				lo = mid;
			}
			else
				hi = mid;
		}
		printf("%.4f\n", szbst);

	}

	return 0;
}
