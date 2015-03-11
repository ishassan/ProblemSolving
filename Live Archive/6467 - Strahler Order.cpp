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

const int SIZE = 1005;
vector<vector<int> > outNodes;
vector<vector<int> > inNodes;
vector<int> output;
void topologicalSort(int n)
{
     output.clear();
     vector<int> outDegree(n + 1);
     for (int i = 0; i < n; ++i)
          outDegree[i] = (int)(outNodes[i].size());
     set<int> zeros;
     for (int i = 0; i < n; ++i)
          if (outDegree[i] == 0)
               zeros.insert(i);
     while (zeros.size()) {
          int cur = *zeros.begin();
          zeros.erase(cur);
          output.push_back(cur);
          for (int i = 0; i < (int)(inNodes[cur].size()); ++i) {
               int parent = inNodes[cur][i];
               if ((--outDegree[parent]) == 0)
                    zeros.insert(parent);
          }
     }
     reverse(all(output));
}
int n,m;
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     int tst,tt,a,b;
     cin >> tst;
     while (tst--) {
          cin >> tt >> n >> m;
          inNodes = vector<vi>(n+5);
          outNodes = vector<vi>(n+5);
          rep(i,m) {
               cin >> a >> b;
               --a,--b;
               outNodes[a].push_back(b);
               inNodes[b].push_back(a);
          }
          topologicalSort(n);
          vi res(n);
          rep(i,n){
               int cur = output[i];
               if(sz(inNodes[cur]) == 0){
                    res[cur] = 1;
                    continue;
               }
               int mx=-1,cnt=0;
               repi(it,inNodes[cur]){
                    if(mx < res[*it])mx = res[*it],cnt=1;
                    else if(mx == res[*it]) cnt++;
               }
               if(cnt == 1)res[cur] = mx;
               else res[cur] = mx+1;
               if(sz(outNodes[cur]) == 0){
                    cout << tt << " " << res[cur] << endl;
                    break;
               }
          }
     }

     return 0;
}
