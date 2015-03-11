#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mt make_tuple
#define tii tuple<int,int>
#define at(t,idx) std::get<(idx)>((t))
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (int((find((v).begin(), (v).end(),(x))-(v).begin() + 1)%((v).size()+1))-1)

typedef long long ll;
using namespace std;

int n,k,m;
int memo[1002][102][2];

ll powr(ll n, ll p, ll mod)
{
     if(p == 0)     return 1;
     if(p == 1)     return n;
     ll x = powr(n, p / 2, mod);
     x = (x * x)%mod;
     if(p & 1)
          x = (x * n)%mod;
     return x;
}

int DP(int idx, int rem, bool nonzero){
     if(nonzero && rem == 0){
          int remdig = n-idx;
          if(remdig == 0) return 1;
          return (9*powr(10,remdig-1, m))%m;
     }
     if(idx == n) return 0;
     int& ref = memo[idx][rem][nonzero];
     if(ref != -1) return ref;
     ref = 0;
     int start = idx+1==n?1:0;
     repa(i,start,9,1){
          int newrem = (i * powr(10,idx,k)) % k;
          newrem = (newrem + rem)%k;
          ref = (0LL + ref + DP(idx+1, newrem, nonzero || i>0))%m;
     }
     return ref;
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     while(cin >> n >> k >> m){
          mem(memo,-1);
          cout << DP(0,0,0) << "\n";
     }
     return 0;
}