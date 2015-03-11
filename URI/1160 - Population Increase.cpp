#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mt make_tuple
#define tii tuple<int,int>
#define at(t,idx) std::get<(idx)>((t))
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (int((find((v).begin(), (v).end(),(x))-(v).begin() + 1)%((v).size()+1))-1)

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
     int tst;
     cin >> tst;
     while(tst--){
          double ga,gb;
          ll a,b;
          cin >> a >> b >> ga >> gb;
          ga /= 100.0 , gb /= 100.0;
          bool yes=0;
          repa(i,1,100,1){
               ll adda = ga*a,  addb = gb*b;
               a += adda, b += addb;
               if(a > b){
                    printf("%d anos.\n",i); 
                    yes=1;
                    break;
               }
          }
          if(!yes){
               printf("Mais de 1 seculo.\n");
          }
     }
     return 0;
}
