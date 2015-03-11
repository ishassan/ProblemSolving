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

vector<vector<pair<int,bool> > > g;
int nrev[3003],depth[3003];
bool vis[3003];
int n,totrev;

void dfs(int u, int p, int curlen, int currev){
     vis[u] = 1;
     nrev[u] = currev;
     depth[u] = curlen;
     for(pair<int,bool> nxt: g[u]){
          if(nxt.first == p || vis[nxt.first]) continue;
          totrev += nxt.second;
          dfs(nxt.first, u, curlen+1, currev + nxt.second);
     }
}
int calc(int u, int p, int r){
     totrev=0;
     mem(vis,0);
     dfs(u,p,0,0);
     int mn=1<<27;
     rep(i,n){
          if(vis[i]){
               int res = (totrev - nrev[i]) + (depth[i] - nrev[i]);
               if(res < mn) mn=res, r=i;
          }
     }
     return mn;  
}
int main()
{
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     int a,b;
     cin >> n;
     
     g.resize(n+5);
     rep(i,n-1){
          cin >>a >>b, --a,--b;
          g[a].push_back(mp(b,0));
          g[b].push_back(mp(a,1));
     }
     if(n==1){cout << 0; return 0;}
     int mn = 1<<27;
     pii p;
     rep(i,n){
          rep(j,sz(g[i])){
               int nxt = g[i][j].first;
               int res = calc(i,nxt, a) + calc(nxt,i,b);
               if(res < mn) mn=res, p = mp(a,b);
          }
     }
     cout << mn;
     return 0;
}
