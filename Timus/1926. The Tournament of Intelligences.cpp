#include <bits/stdc++.h>
#include <ext/numeric>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

struct mul{
    ll mod;
    mul(ll m):mod(m){}
    ll operator()(ll a, ll b){
        return ((a%mod)*(b%mod))%mod;
    }
};

ll identity_element(const mul&){
    return 1LL;
}

//===================
#define eg(r0,r1) t=r0-r*r1,r0=r1 ,r1=t

ll Egcd(ll r0, ll r1, ll &x0, ll &y0) {
  ll y1 = x0 = 1, x1 = y0 = 0;
  while (r1) {
    ll r = r0 / r1;
    ll t;
//    t=r0-r*r1;
//    r0=r1;
//    r1=t;
//
//    t=x0-r*x1;
//    x0=x1;
//    x1=t;
//
//    t=y0-r*y1;
//    y0=y1;
//    y1=t;

    eg(r0, r1);
    eg(x0, x1);
    eg(y0, y1);

  }
  //r0=gcd(a,b)
  return (r0 < 0) ? (x0 *= -1, y0 *= -1, -r0) : r0;

}

// linear Difontien Equation
bool solveLDE(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
  g = Egcd(a, b, x, y);

  ll m = c / g;
  x *= m;
  y *= m;

//  bool ret = ;
  return !(c % g);
}

bool CRT(ll m[], ll r[], ll &M, ll &R, int siz) {
  M = m[0];
  R = r[0];
  for (int i = 1; i < siz; i++) {
    ll x, y, g;
    if (!solveLDE(M, -m[i], r[i] - R, x, y, g))
      return 0;
    // merge equations
    x %= (m[i] / g); // y %= (M / g);
    ll nr = x * M + R; // y * m[i] + r[i]; // => another solution
    ll nm = M / g * m[i]; // lcm
    nr %= nm;
    R = nr, M = nm;
  }
  if(M) R = ((R%M)+M)%M;
  return 1;
}
//===========================


ll mods[50],m[50],r[50];
void calcmod(string& str, ll mod){
    ll pw=1,res=0;
    repd(i,sz(str)-1,0,1){
        res += (str[i]-'0')*pw;
        res %= mod;
        pw = (pw*10)%mod;
    }
    mods[mod] = res;
}
void updateMod(string& str, ll idx, ll dig){
    ll val = dig - (str[sz(str)-idx-1] - '0');
    str[sz(str)-idx-1] = dig+'0';
    repa(i,2,49,1){
        ll v = (val*power(10,idx,mul(i)))%i;
        mods[i] += v;
        mods[i]=((mods[i]%i)+i)%i;
    }
}
//==========================================
const int MAX = 1000000;
long long primepow[MAX], prime[MAX], nprimes = 0;

void factorization(long long n) { // O(sqrt(n))
    nprimes = 0;
    long long pow = 0;
    int d = 1;
    for (long long i = 2; i * i <= n; i += d, d = 2) {
        pow = 0;
        while (!(n % i))	pow++, n /= i;
        if (pow != 0)
            primepow[nprimes] = pow, prime[nprimes++] = i;
    }
    if (n > 1)
        primepow[nprimes] = 1, prime[nprimes++] = n;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif

    string str;
    cin >> str;
    repa(i,2,49,1)   calcmod(str,i);
    ll q,t,idx,dig;
    ll md;
    cin >> q;
    while(q--){
        cin >> t;
        if(t == 0){
            cin >> md;
            if(md == 1) {cout <<"0\n"; continue;}
            factorization(md);
            rep(i,nprimes){
                m[i] = prime[i];
                r[i] = mods[m[i]];
            }
            ll M,R;
            CRT(m,r,M,R,nprimes);
            cout << R << "\n";
        }
        else{
            cin >> idx >> dig;
            --idx;
            updateMod(str,idx,dig);
        }
    }

    return 0;
}
