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

double memo[1002][1002][3];
double DP(int w, int b, int tp)
{
     if (w <= 0 || b < 0) return 0;
     if (w == 0 && b == 0) return 0;
     double& m = memo[w][b][tp];
     if (m == m) return m;
     double dw=w,db=b;
     
     if (tp == 0) {
          m = dw/(dw+db);
          m += DP(w, b-1, (tp+1)%3) * ( db/(dw+db) );
     } else if(tp == 1){
          m = DP(w, b-1,(tp+1)%3) * (db / (dw+db));
     }
     else{
          m = DP(w-1,b,(tp+1)%3) * (dw/(dw+db));
          m += DP(w,b-1,(tp+1)%3) * (db/(dw+db));
     }
     return m;
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     mem(memo,-1);
     int w,b;
     cin >> w >> b;
     printf("%.10lf\n",DP(w,b,0));
     return 0;
}
