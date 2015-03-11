#include <bits/stdc++.h>

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


//ax+by=gcd(a,b)
// a,b inputs, x,y outputs
// There will be many solution to the equation above on the form of:
// { (x+(k*b)/GCD(a,b)  , y-(k*a)/GCD(a,b)) | k belongs to Z} according to Beziout's Identity
ll eGCD(ll a, ll b, ll &x, ll &y) {
    x = 1;
    y = 0;
    ll nx = 0, ny = 1;
    ll t, r;
    while (b) {
        r = a / b;
        t = a - r * b;
        a = b;
        b = t;
        t = x - r * nx;
        x = nx;
        nx = t;
        t = y - r * ny;
        y = ny;
        ny = t;
    }
    return a;
}

//(a*mi)%m=1
ll modInv(ll a, ll m) {
    ll mi, r;
    eGCD(a, m, mi, r);
    return (mi + m) % m;
}

long long PowerMod(ll x, ll p, ll m) {
    if (!p)
        return 1;
    long long y = PowerMod(x, p >> 1, m);
    y = y%m;
    y = (y * y) % m;
    if (p & 1)
        y = (y * x) % m;
    return y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("main.txt","rt",stdin);
//    //  freopen("out.txt","wt",stdout);
//#endif

    int n,e,c;
    while(cin >> n >> e >> c){
        factorization(n);
        ll toti =1LL* (prime[0]-1)*(prime[1]-1);
        ll d = modInv(e, toti);
        cout << PowerMod(c,d,n) << "\n";

    }

    return 0;
}

