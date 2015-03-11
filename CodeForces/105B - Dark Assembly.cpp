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

int n,k,a;
pii arr[10];

double calc_prob_yes(int idx, int rem, int needkill)
{
     if(rem == 0) return 1;
     if(idx == n) return (a+0.0) / (a+needkill+0.0);
     
     double res = calc_prob_yes(idx+1, rem, needkill+arr[idx].first) * (1-arr[idx].second/10.0);
     if (rem)
          res += calc_prob_yes(idx+1,rem-1,needkill)*(arr[idx].second/10.0);
     return res;
}
double dfs(int idx, int remk)
{
     if (idx == n) {
          return calc_prob_yes(0, n/2+1,0);
     }

     double res = 0;
     repa(i,0,remk,1) {
          if (arr[idx].second + i > 10) break;
          arr[idx].second += i;
          res = max(res, dfs(idx+1,remk-i));
          arr[idx].second -= i;
     }

     return res;

}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     cin >> n >> k >> a;
     rep(i,n)
     cin >> arr[i].first >> arr[i].second, arr[i].second/=10;

     printf("%.10lf\n",dfs(0,k));

     return 0;
}
