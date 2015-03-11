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

int n,l,k;
int prob[202],p;
vector<pair<int,double> > v;
double memo[202][202][500];
double DP(int idx, int remwin, int cap)
{
     if(cap < 0) return 0.0;
     if (idx == n) return remwin==0;
     
     double& m = memo[idx][remwin][cap];
     if (m == m) return m;

     m = DP(idx+1, max(0,remwin-1), min(400, cap+v[idx].first)) * v[idx].second;
     m += DP(idx+1, remwin, cap) * (1.0 - v[idx].second);
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

     cin >> n >> l >> k;
     rep(i,n) cin >> prob[i];
     rep(i,n) {
          cin >> p;
          v.emplace_back(p, prob[i]/100.0);
     }
     sort(rall(v));
     mem(memo,-1);
     printf("%.7lf\n", DP(0,l,k));
     return 0;
}
