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
#include <complex>

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
#define fnd(v,x) (find(all((v)),(x))!=(v).end())

using namespace std;

typedef complex<long double> point;
typedef long double ld;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-13
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine

typedef long long ll;

vector<point> a;
vector<pair<long double, int> > v;

ld getAngle(point about, point p) {
	return angle(p - about);
}

ld dist(point p1, point p2) {
	return (p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y);
}

bool intersect(const point &a, const point &b, const point &p, const point &q, point &ret) {
	long double d1 = cross(p - a, b - a);
	long double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	return fabs(d1 - d2) > EPS;
}

inline bool eq(ld a, ld b){
	return fabs(a-b)<EPS;
}
int main() {
	int n, m, x, y;
	scanf("%d", &n);
	a = vector<point>(n);
	v = vector<pair<long double, int> >(n);
	point center(0, 0);
	rep(i,n) {
		scanf("%d%d", &x, &y);
		a[i] = point(x, y);
		center.X += x, center.Y += y;
	}
	center.X /= n, center.Y /= n;

	rep(i,n)
		v[i] = mp(getAngle(center, a[i]), i);

	sort(all(v));

	scanf("%d", &m);
	bool yes = 1;
	rep(i,m) {
		scanf("%d%d", &x, &y);
		if (fabs(center.X - x) + fabs(center.Y - y) <= EPS)
			continue;
		point b = point(x, y);
		ld ang = getAngle(center, b);
		pair<ld, int> nxt = v[(lower_bound(all(v), mp(ang,-1)) - v.begin()) % n];
		int idx = nxt.second;
		if (eq(nxt.first,ang)) {
			if (dist(center, b) > dist(center, a[idx]) || eq(dist(center, b) , dist(center, a[idx]))) {
				yes = 0;
				break;
			}
		}
		else{
			int idx2 = (idx+1)%n;
			point res;
			intersect(center,b,a[idx],a[idx2],res);
			ld db = dist(center,b);
			ld dr = dist(center,res);
			if(db> dr || eq(db,dr)) {
				yes=0;
				break;
			}
		}

	}

	printf(yes?"YES":"NO");
	return 0;
}
