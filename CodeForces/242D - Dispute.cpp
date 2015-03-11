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

const int SIZE =100005;
int cnt[SIZE],goal[SIZE];
vi g[SIZE];
int main()
{

#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     int n,m,a,b;
     cin >> n >> m;
     rep(i,m) {
          cin >> a >> b;
          g[a].push_back(b);
          g[b].push_back(a);
     }
     queue<int> q;
     repa(i,1,n,1) {
          cin >> goal[i];
          if (goal[i] == 0) q.push(i);
     }
     vi res;
     while (q.size()) {
          int idx = q.front();
          q.pop();
          if (cnt[idx] != goal[idx]) continue;
          res.push_back(idx);
          cnt[idx]++;
          rep(i,sz(g[idx])) {
               int nxt = g[idx][i];
               if (++cnt[nxt] == goal[nxt])
                    q.push(nxt);
          }
     }
     bool no=0;
     repa(i,1,n,1) no |= cnt[i] == goal[i];
     if (no) cout << -1;
     else {
          cout << sz(res) << endl;
          rep(i,sz(res))
          cout << res[i] <<" ";
     }
     return 0;
}
