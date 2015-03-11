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

const int MAXN = 101;
vector<vi> adj;
int vis[MAXN], visID = 0;
deque<int> res;

void recTopo(int idx) {
    if (vis[idx] == visID)
        return;
    vis[idx] = visID;
    for(int nxt : adj[idx]) recTopo(nxt);
    res.push_front(idx);
}
void topo(int n){
    ++visID;
    res.clear();
    for (int i = 0; i < n; ++i)
      recTopo(i);
}
int n,m;
int main() {
  std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
  freopen("main.txt","rt",stdin);
  //  freopen("out.txt","wt",stdout);
#endif
  int f, t;
  while (cin >> n >> m && n) {
    adj = vector<vi>(n+5);
    while (m--) {
      cin >> f >> t;
      --f,--t;
      adj[f].push_back(t);
    }
    topo(n);
    for (int i = 0; i < (int) res.size(); i++)
      cout << res[i]+1 << " \n"[i == (int) res.size() - 1];
  }
  return 0;
}
