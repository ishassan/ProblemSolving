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

struct state {
     ll t,x,y;
     double p;
     bool operator<(const state& st)const {
          return t < st.t;
     }
} arr[1005];
int n;
double memo[1002][1002];
double DP(int idx=1, int lst=0)
{
     if (idx > n) return 0;
     double& m = memo[idx][lst];
     if (m == m) return m;

     m = DP(idx+1,lst);
     if (!lst)
          m = max(m,DP(idx+1,idx)+arr[idx].p);
     else if ((arr[idx].x - arr[lst].x)*(arr[idx].x - arr[lst].x) + (arr[idx].y - arr[lst].y)*(arr[idx].y - arr[lst].y) <= (arr[idx].t - arr[lst].t) *(arr[idx].t - arr[lst].t))
          m = max(m,DP(idx+1,idx)+arr[idx].p);
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

     cin >> n;
     state st= {-1,-1<<27,-1<<27,1.0};
     arr[0]=st;
     repa(i,1,n,1) {
          cin >> arr[i].x >> arr[i].y >> arr[i].t >> arr[i].p;
     }
     sort(arr,arr+n+1);
     mem(memo,-1);
     printf("%.7lf\n",DP());
     return 0;
}
