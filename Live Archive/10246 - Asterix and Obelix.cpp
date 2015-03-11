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

int n,m,q;
int g[82][82];
int mxnode[82][82];
int cst[82];

void floyd(){
     rep(k,n){
          rep(i,n){
               rep(j,n){
                    if(g[i][j] + mxnode[i][j] > g[i][k] + g[k][j] + max(mxnode[i][k], mxnode[k][j])){
                         g[i][j] = g[i][k] + g[k][j];
                         mxnode[i][j] = max(mxnode[i][k], mxnode[k][j]);
                    }
               }
          }
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
     int tst=1;
     char* en="";
     while (cin >> n >> m >> q && (n || m || q)) {
          mem(g,0x3f);
          mem(mxnode,-1);
          rep(i,n) {
               g[i][i] = 0;
               mxnode[i][i] = 0;
          }
          rep(i,n) cin >> cst[i];
          int a,b,c;
          rep(i,m){
               cin >> a >> b >> c;
               --a,--b;
               g[b][a] = (g[a][b] = min(g[a][b], c));
               mxnode[a][b] = (mxnode[b][a] = max(mxnode[b][a], max(cst[a], cst[b])));
          }
          floyd();
          floyd();
          printf("%sCase #%d\n",en,tst++); en="\n";
          while(q--){
               cin >> a >> b;
               --a, --b;
               printf("%d\n",(g[a][b]+mxnode[a][b] > (1<<27))?-1:g[a][b]+mxnode[a][b]);
          }
     }

     return 0;
}
