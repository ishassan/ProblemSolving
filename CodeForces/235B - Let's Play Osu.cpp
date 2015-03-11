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

//http://codeforces.com/blog/entry/5592
//Thanks to ghooo :D

/*
 * 2*nC2 + n = n^2 ?
 * nC2 = n*(n-1)/2
 * 2*nC2 + n = n*(n-1) + n = n^2 = RHS
 * 
 * dp(j-1) = event(0,j-1) + event(1,j-1) + event(2,j-1) + ... + event(j-2,j-1)
 * dp(j) = event(0,j) + event(1,j) + event(2,j) + ... + event(j-1,j)
 * 
 * dp(j-1)*pj = event(0,j) + event(1,j) + .. + event(j-2,j)
 * 
 * dp(j) = dp(j-1)*pj + event(j-1,j)
 *       = dp(j-1)*pj + (pj-1 * pj)
 *       = (dp(j-1) + pj-1) * pj
 * 
 * QED
 */
double prob[100005];
double memo[100005];
double DP(int n){
     if(n == 0) return 0;
     double& m = memo[n];
     if(m == m) return m;
     return m = (DP(n-1) + prob[n-1]) * prob[n];
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif
     
     int n;
     cin >> n;
     rep(i,n) cin >> prob[i];
     mem(memo,-1);
     
     double res = 0;
     rep(i,n) res += 2*DP(i) + prob[i];
     
     printf("%.7lf\n",res);

     return 0;
}
