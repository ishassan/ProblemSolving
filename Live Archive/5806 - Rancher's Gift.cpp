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
typedef long long ll;
using namespace std;

typedef complex<long double> point;

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
#define itr(A,B) typeof(B) A = B


#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
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

long double triangleArea3points( point a,  point b, point c) {
    return fabs(cross(a,b) + cross(b,c) + cross(c,a)) / 2;
}
bool intersect(const point &a, const point &b, const point &p, const point &q, point &ret) {
    long double d1 = cross(p - a, b - a);
    long double d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    return fabs(d1 - d2) > EPS;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
//    freopen("out","wt",stdout);
#endif

    int tst;
    scanf("%d",&tst);
    while(tst--){
        int t;
        long double bx,cx,cy,dx,dy;
        scanf("%d%Lf%Lf%Lf%Lf%Lf",&t,&bx,&cx,&cy,&dx,&dy);
        long double adx = (bx+cx)/2.0+EPS, ady = cy/2.0+EPS;
        long double bdx = (cx+dx)/2.0+EPS, bdy = (cy+dy)/2.0+EPS;
        long double cdx = (dx)/2.0+EPS, cdy = (dy)/2.0+EPS;
        long double ddx = (bx)/2.0+EPS, ddy = 0;

        point a = point(0,0), b = point(bx,0), c = point(cx,cy), d = point(dx,dy);
        point ad = point(adx,ady), bd = point(bdx,bdy), cd = point(cdx,cdy), dd = point(ddx,ddy);

        point ea,eb,ec,ed;
        intersect(a,ad,d,dd,ea);
        intersect(b,bd,a,ad,eb);
        intersect(c,cd,b,bd,ec);
        intersect(d,dd,c,cd,ed);

        long double a1 = triangleArea3points(a,b,eb)/160+EPS;
        long double bob = triangleArea3points(b,c,ec)/160+EPS;
        long double chas = triangleArea3points(c,d,ed)/160+EPS;
        long double dav = triangleArea3points(d,a,ea)/160+EPS;
        long double emily = (triangleArea3points(ea,eb,ed)+triangleArea3points(ec,eb,ed))/160+EPS;
        point eab = vec(ea,eb), ebc = vec(eb,ec), ecd = vec(ec,ed), eda = vec(ed,ea);
        int m = ceil((length(eab) + length(ebc) + length(ecd) + length(eda))*16.5);
        printf("%d %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %d\n",t,a1,bob,chas,dav,emily,m);
    }

    return 0;
}





