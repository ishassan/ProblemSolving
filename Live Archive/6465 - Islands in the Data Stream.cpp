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

     int tst,tt;
     cin >> tst;
     repa(t,1,tst,1){
          cin >> tt;
          int arr[15];
          rep(i,15) cin >> arr[i];
          int res = 0;
          repa(i,1,13,1){
               repa(j,i,13,1){
                    int mn = 1<<27;
                    repa(k,i,j,1)
                         mn = min(mn, arr[k]);

                    res += (mn > arr[i-1] && mn > arr[j+1]);
               }
          }
          cout << tt << " " << res << endl;
          
     }
     return 0;
}
