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

     int n[2],m,x;
     int tst=1;
     while (cin >> n[0] >> n[1] >> m && (n[0] || n[1] || m)) {
          set<int> idx[2];
          vector<vi> t(2,vi(2000,-1));
          while (m--) {
               cin >> x;
               int turn=0;
               while (1) {
                    int md = x%n[turn];
                    idx[turn].insert(md);
                    if (t[turn][md] == -1) {
                         t[turn][md] = x;
                         break;
                    }
                    swap(t[turn][md],x);
                    turn =!turn;
               }
              
          }
          printf("Case %d:\n", tst++);
          vector<pii> res1,res2;
          repi(it,idx[0]){
               res1.push_back(mp(*it, t[0][*it]));
          }
          repi(it,idx[1]){
               res2.push_back(mp(*it, t[1][*it]));
          }
          if(sz(res1)){
               printf("Table 1\n");
               rep(i,sz(res1)) printf("%d:%d\n", res1[i].first,res1[i].second);
          }
          if(sz(res2)){
               printf("Table 2\n");
               rep(i,sz(res2)) printf("%d:%d\n", res2[i].first,res2[i].second);
          }
                    
          
     }

     return 0;
}
