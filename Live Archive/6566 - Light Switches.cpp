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

void factorization(long long n)   // O(sqrt(n))
{
     nprimes = 0;
     long long pow = 0;
     int d = 1;
     for(long long i = 2; i *i <= n; i += d, d = 2) {
          pow = 0;
          while(!(n % i))        pow++, n /= i;
          if(pow != 0)
               primepow[nprimes] = pow, prime[nprimes++] = i;
     }
     if(n > 1)
          primepow[nprimes] = 1, prime[nprimes++] = n;
}
//call factorization before calling this
long long divs[MAX];//holds divisors
int sz = 0;
void generate_divisors(int ind = 0, long long mul = 1)
{
     
     if(ind == nprimes) {
          divs[sz++] = mul;
          return;
     }
     long long x = 1;
     for(int i = 0; i <= primepow[ind]; i++) {
          generate_divisors(ind + 1, mul * x);
          x *= prime[ind];
     }
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     ll n,t,b;
     int tst=1;
     while(cin >> n >> t >> b){
          sz = 0;
          t %= n;
          factorization(b);
          generate_divisors();
          sort(divs,divs+sz);
          int num = upper_bound(divs, divs+sz,t)-divs;
          cout << "Case " << tst++ << ": " <<((num&1)?"On\n":"Off\n");
     }
     return 0;
}
