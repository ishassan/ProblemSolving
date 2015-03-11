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

vi v;
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
     #endif
     
     int tst,tt,m;
     cin >> tst;
     while(tst--){
          cin >> tt >> m;
          v.clear();
          int a=0,b=1,c;
          v.push_back(0);
          v.push_back(1);
          int idx=-1,len;
          repa(i,2,3000000,1) {
               c = (a+b)%m;
               if (i<10) v.push_back(c);
               if (idx==-1 && c==0) idx=0,len=i;
               else if (idx > -1 && idx+1<sz(v) && idx < len) {
                    if (c==v[idx+1])++idx;
                    else idx=-1;
                    
               }
               if (idx == min(len,sz(v)-1)) {
                    cout << tt<<" "<< len <<endl;
                    break;
               }
               a=b;
               b=c;
          }
     }
     
     return 0;
}