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
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;

#include <complex>
typedef complex<long double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-7
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

int mn=1<<27, smval=0;
inline void update(int sum1, int sum2)
{
    if(sum1 == 0 || sum2 == 0) return;
    if(mn > abs(sum1 - sum2)){
        mn = abs(sum1 - sum2);
        smval = min(sum1,sum2);
    }
    else if(mn == abs(sum1 - sum2)){
        int tmp = min(sum1,sum2);
        smval = max(smval, tmp);
    }
    
}

double toDeg(double rad)
{
    return rad * 180 / M_PI;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
#endif

    int n;
    scanf("%d", &n);
    vector<pair<int, point> > v(n);
    rep(i, n) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        v[i] = mp(c, point(x, y));
    }
    rep(i, n) {
        repa(j, i + 1, n - 1, 1) {
            point line = vec(v[i].second, v[j].second);
            int sum1 = 0, sum2 = 0;
            rep(k, n) {
                if(k == i || k == j) continue;
                point line2 = vec(v[i].second, v[k].second);
                long double dir = cross(line,line2);
                if(dir > 0) sum1 += v[k].first;
                else sum2 += v[k].first;
            }
            int nsum = sum1 + v[i].first + v[j].first;
            update( nsum, sum2);

            nsum = sum2 + v[i].first + v[j].first;
            update( sum1, nsum);

            update( sum1 + v[i].first, sum2 + v[j].first);
            update( sum1 + v[j].first, sum2 + v[i].first);
        }
    }

    printf("%d\n", smval);
    return 0;
}