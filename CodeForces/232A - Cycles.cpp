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

inline ll nc3(ll n){
     return n*(n-1)*(n-2)/6;
}

ll arr[200];
int k;
bool g[102][102];

int getnodes(int cur, int n, ll rem){
     if(rem == 0) return 0;
     rep(i,n){
          ll tmp = rem-(i*(i+1))/2;
          if(tmp < 0){
               tmp = rem-(i*(i-1))/2;
               return getnodes(cur+1,n,tmp)+1;
          }
          g[cur][i] = g[i][cur]=1;
     }
     return 1e9;
}
int main()
{

#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif
     rep(i,200) arr[i] = nc3(i);
     cin >> k;
     int idx = upper_bound(arr,arr+200,k)-arr-1;
     rep(i,idx){
          repa(j,i+1,idx-1,1)
               g[i][j] = g[j][i]=1;
     }
     int n = getnodes(idx, idx, k-arr[idx])+idx;
     cout << n << endl;
     rep(i,n){
          rep(j,n) cout << g[i][j];
          cout << endl; 
     }
     return 0;
}
