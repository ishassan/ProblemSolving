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

ll pre[102][102][302];
int mod = 1000000007;
ll precalc(int idx, int lim, int rem)
{
    if(rem == 0)  return 1;
    ll &m = pre[idx][lim][rem];
    if(m != -1) return m;
    m = 0;
    if(idx + 1 <= lim)
        m += precalc(idx + 1, lim, rem - 1);
    if(idx - 1 > 0)
        m += precalc(idx - 1, lim, rem - 1);
    m %= mod;
    return m;
}

//solves ax + by = c. x,y are unknowns
//x is the multiplicative inverse of a modulo b, and y is the multiplicative inverse of b modulo a.
pair<ll, ll> extended_eculidean(ll a, ll b, ll c) {
        ll gcd = __gcd(a, b);
        if (c % gcd)
                return mp(1LL<<60,1LL<<60);

        ll x0 = 1, y0 = 0, R0 = a;
        ll x1 = 0, y1 = 1, R1 = b;

        ll resR = 0;
        while (R1) {
                ll q = R0 / R1;
                resR = R0 - q * R1;
                R0 = R1, R1 = resR;

                ll newX = x0 - q * x1;
                x0 = x1, x1 = newX;

                ll newY = y0 - q * y1;
                y0 = y1, y1 = newY;
        }
        return mp(x0,y0);
}
ll chooseMemo[302][302];
ll choose(int n, int k, int mod){ //mod and k! coprimes
    // n*(n-1)..*(n-k+1) / k!
    // numerator
    ll &m = chooseMemo[n][k];
    if(m != -1) return m;
    
    int tmpn = n, tmpk=k;
    ll num=1;
    while(tmpk--){
        num *= tmpn--;
        num %= mod;
    }
    // denomerator
    tmpk = k;
    ll denum=tmpk;
    while(--tmpk){
        denum *= tmpk;
        denum %= mod;
    }
    
    //result == num/denom == num*(1/denom) == num*MultiInver(denom) [mod M]
    ll num2 = extended_eculidean(denum, mod, 1).first%mod;
    ll res = (num*num2)%mod;
    return m = ((res+mod)%mod);
}
int n,s;
int cur[11],lim[11];
ll memo[11][302];
ll DP(int dim, int rem){
    if(rem == 0) return 1;
    if(dim == n) return 0;
    ll& m = memo[dim][rem];
    if(m != -1) return m;
    
    m=0;
    repa(i,0,rem,1){
        ll x1 = precalc(cur[dim], lim[dim], i);
        ll x2 = DP(dim+1, rem-i);
        ll x3 = i==0?1:choose(rem,i, mod);
        m += ((x1 * x2)%mod) * x3;
        m %= mod;
    }
    return m;
}
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
// #endif

    mem(pre, -1);
    mem(chooseMemo,-1);
    int tst;
    scanf("%d",&tst);
    while(tst--){
        scanf("%d%d",&n,&s);
        rep(i,n) scanf("%d",cur+i);
        rep(i,n) scanf("%d",lim+i);
        rep(i,n) precalc(cur[i], lim[i], s);
        mem(memo,-1);
        printf("%lld\n", DP(0,s));
        
    }
    return 0;
}