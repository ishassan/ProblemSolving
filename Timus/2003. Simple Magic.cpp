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
int cntprime[10000002];

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
    //  freopen("out.txt","wt",stdout);
#endif

    int n,x,mx=0;
    cin >> n;
    rep(i,n) {
        cin >> x;
        factorization(x);
        rep(i,nprimes)
            mx=max(mx,++cntprime[prime[i]]);
    }
    if(mx > 2) cout << "infinity\n";
    else cout << mx << "\n";

    return 0;
}

