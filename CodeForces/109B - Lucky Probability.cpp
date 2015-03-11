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
#define pll pair<long long,long long>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

vector<ll> luk;
inline ll intersect(pll a, pll b)
{
     ll res = min(a.second,b.second) - max(a.first,b.first)+1;
     return max(0ll,res);
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     luk.push_back(0);
     repa(i,1,10,1) {
          for (ll j=0; j< (1LL<<i); j++) {
               ll num=0;
               rep(k,i) {
                    num *= 10;
                    num += ( (1<<k)&j )?7:4;
               }
               luk.push_back(num);
          }
     }
     luk.push_back(1e18);
     sort(all(luk));
     
     pll p,v;
     int k;
     cin >> p.first >> p.second >> v.first >> v.second >> k;
     ll res = 0;
     repa(i,1,sz(luk)-k-1,1) {
          pll st,en;
          st.first = luk[i-1]+1;
          st.second = luk[i];
          en.first = luk[i+k-1];
          en.second = luk[i+k]-1;
          res += intersect(st, v) * intersect(en, p);
          res += intersect(st, p) * intersect(en, v);
          if(k == 1 && intersect(v, mp(luk[i],luk[i])) && intersect(p, mp(luk[i],luk[i])))
               --res;
     }
     printf("%.10lf\n",res/((p.second-p.first+1.0)*(v.second-v.first+1.0)));


     return 0;
}
