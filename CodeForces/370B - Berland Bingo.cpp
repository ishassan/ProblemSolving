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

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     int n;
     while(cin >> n){
          vector<vector<bool> > vis(n, vector<bool>(102,0));
          vector<int> cnt(n,0);
          int m;
          rep(i,n){
               cin >> m;
               cnt[i] = m;
               int x;
               rep(j,m){
                    cin >> x;
                    vis[i][x]=1;
               }
          }
          
          rep(i,n){
               vector<vector<bool> > cpvis = vis;
               vi cpcnt = cnt;
               bool yes=1;
               rep(j,sz(cpvis[i])){
                    if(cpvis[i][j]==0) continue;
                    int sum=0;
                    rep(k,n){
                         if(cpvis[k][j]){
                              cpvis[k][j]=0;
                              cpcnt[k]--;
                              sum += (cpcnt[k]==0);
                         }
                    }
                    if(sum > 1){yes=0; break;}
                    if(sum && cpcnt[i]){yes=0; break;}
                    if(cpcnt[i]==0){yes=1; break;}
               }
               cout << (yes?"YES\n":"NO\n");
          }
          cout << "\n";
     }
     return 0;
}
