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

ll memo[(1<<17)+9];
int n,k;
ll DP(int idx, int msk){
     if(idx == n) return 1;
     ll& m = memo[msk];
     if(m != -1) return m;
     m = 0;
     rep(i,n){
          if((msk >> i) & 1) continue;
          if(idx < k && idx == i) continue;
          m += DP(idx+1, msk | (1<<i));
     }
     return m;
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif
     int tst,tt;
     cin >> tst;
     while(tst--){
          cin >> tt >> n >> k;
          mem(memo,-1);
          cout << tt << " " << DP(0,0) << endl;
     }

     return 0;
}
