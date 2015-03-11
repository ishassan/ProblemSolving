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

int n,m,h,sum;
int arr[1002];
double memo[102][102];
double DP(int rem_n, int rem_h)
{
     if (rem_n == 0) return 0;
     double& m = memo[rem_n][rem_h];
     if ( m == m) return m;

     double totrem = sum-(n-rem_n);
     double take = rem_h / totrem;
     double nottake = (1.0 - take) * DP(rem_n-1, rem_h);
     return m = take + nottake;
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif
     cin >> n >> m >> h;
     --h;
     rep(i,m) cin >> arr[i], sum += arr[i];

     --sum, --arr[h], --n;
     if (sum < n) {
          cout << -1;
          return 0;
     }
     mem(memo,-1);
     printf("%.7lf\n", DP(n, arr[h]));
     return 0;
}

