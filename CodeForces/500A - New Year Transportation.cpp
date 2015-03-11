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


const int SIZE = 30005, OO = 1 << 27;
vector<vector<pair<int,int> > > adjlst;
int n;
int dist[SIZE];
int DijkstraWithHeap(int src, int goal)
{
     mem(dist,0);
     dist[src] = 1;
     priority_queue<pair<int,int>, vector< pair<int,int> >, less< pair<int,int> > > q;
     q.push(make_pair(1, src));
     while(q.size()) {
          src = q.top().second;
          int cst = q.top().first;
          q.pop();
          if(cst != dist[src])
               continue;
          if(src == goal)
               return dist[goal];
          for(auto it = adjlst[src].begin(); it != adjlst[src].end(); ++it){
               int nxt = it->second, nxtc = it->first;
               
               if(dist[nxt] < (dist[src] && nxtc)) {
                    dist[nxt] = dist[src] && nxtc;
                    q.push(make_pair(dist[nxt], nxt));
               }
          }
     }
     return dist[goal];
}

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif
     
     int n,m;
     while(cin >> n >> m){
          adjlst.clear();
          adjlst.resize(n+5);
          --m;
          int a;
          rep(i,n-1){
               cin >> a;
               adjlst[i].push_back(mp(1,i+a));
          }
          int res = DijkstraWithHeap(0,m);
          cout << (res?"YES\n":"NO\n");
     }

     return 0;
}
