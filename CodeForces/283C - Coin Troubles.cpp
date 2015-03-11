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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int mod = 1000000007;
int n,q,t;
const int SIZE = 305;
int vis[SIZE],cst[SIZE];
int par[SIZE], child[SIZE];
int memo[SIZE][100005];
int DP(int idx, int rem){
     if(rem == 0) return 1;
     if(rem < 0 || idx > n) return 0;
     int& m = memo[idx][rem];
     if(m != -1) return m;
     m = DP(idx,rem-cst[idx]);
     m += DP(idx+1, rem);
     m %= mod;
     return m;
}
// int res[SIZE];
// void build(int idx, int rem){
//      if(rem == 0) {
//           repa(i,1,n,1) cout << res[i] << " \n"[i==n];
//           return;
//      }
//      if(rem < 0 || idx > n) return;
//      
//      if(DP(idx,rem-cst[idx])){
//           res[idx]++;
//           build(idx,rem-cst[idx]);
//           res[idx]--;
//      }
//      if(DP(idx+1, rem))
//           build(idx+1,rem);
//      
// }
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif
     
     cin >> n >> q >> t;
     repa(i,1,n,1) cin >> cst[i];
     int a,b;
     while(q--){
          cin >> a >> b;
          child[a] = b;
          par[b] = a;
     }
     repa(i,1,n,1){
          if(vis[i]) continue;
          deque<int> q;
          int j;
          for(j = i; j && !vis[j]; j=child[j]){
               q.push_back(j);
               vis[j] = 1;
          }
          if(vis[j]){cout << 0; return 0;}
          for(j = par[i]; j && !vis[j]; j=par[j]){
               q.push_front(j);
               vis[j]=1;
          }
          if(vis[j]){cout << 0; return 0;}
          for(j=0; j<sz(q); j++){
               t -= (sz(q)-j-1) * cst[q[j]];
               if(t < 0){cout << 0; return 0;}
//                res[q[j]] += (sz(q)-j-1);
               if(j) cst[q[j]] += cst[q[j-1]];
          }
     }
     
     mem(memo,-1);
     cout << DP(1,t) << endl;
//      build(1,t);
     return 0;
}
