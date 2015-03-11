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
int nrev[300006],depth[300006];
bool vis[300006];
int n,totrev;

void dfs(int u, int curlen, int currev)
{
     vis[u] = 1;
     nrev[u] = currev;
     depth[u] = curlen;
     for (pair<int,bool> nxt: g[u]) {
          if (vis[nxt.first]) continue;
          totrev += nxt.second;
          dfs(nxt.first,  curlen+1, currev + nxt.second);
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

     int a,b;
     cin >> n;
     g.resize(n+5);
     rep(i,n-1) {
          cin >>a >>b, --a,--b;
          g[a].push_back(mp(b,0));
          g[b].push_back(mp(a,1));
     }
     dfs(0,0,0);
     int mn = 1<<27;
     vi v;
     rep(i,n) {
          int res = (totrev - nrev[i]) + (depth[i] - nrev[i]);
          if (mn > res) mn=res, v.clear();
          if (res == mn) v.push_back(i);
     }

     cout << mn << endl;
     rep(i,sz(v)) cout << v[i]+1 << " ";
     return 0;
}
