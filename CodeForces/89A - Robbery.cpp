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

int main()
{

#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     ll n,m,k;
     cin >> n >> m >> k;
     ll arr[10005];
     ll mn = 1LL<<60;
     rep(i,n) {
          cin >> arr[i];
          if(i%2==0) mn = min(mn, arr[i]);
     }
     if(n == 1){
          cout << min(arr[0], m*k);
          return 0;
     }
     if(n % 2 == 0){
          cout << 0;
          return 0;
     }
     // n/2 + 1 => time to steal 1 diamond
     cout << min(mn, (m/(n/2+1))*k);
     
     return 0;
}
