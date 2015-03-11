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
#define pdd pair<double,double>
typedef long long ll;
using namespace std;

pdd pnt[50002];
int n;
double eps = 1.0e-10;

double hypot(double x, double y) {
	return sqrt(x * x + y * y);
}

double calc(double x) {
	double mx = -1e9;
	fo(i,n)
		mx = max(mx, hypot(abs(x - pnt[i].first), pnt[i].second));
	return mx;
}

int main() {
	while (scanf("%d", &n) != -1 && n) {
		double s = 1e9, e = -1e9;
		fo(i,n) {
			scanf("%lf%lf", &pnt[i].first, &pnt[i].second);
			s = min(s, pnt[i].first);
			e = max(e, pnt[i].first);
		}

		double mid1,mid2,c1,c2;
		while (abs(s - e) > eps) {
			mid1 = (2*s+e)/3;	//original eq: s+((e-s)/3) -> third from left
			mid2 = (s+2*e)/3;	//original eq: s+((e-s)*2/3) -> third from right

			c1 = calc(mid1),c2=calc(mid2);

			if(c1<c2)
				e = mid2;
			else
				s = mid1;
		}
		printf("%.9lf %.9lf\n", s, calc(s));
	}

	return 0;
}
