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

const double eps=1e-8;
int dcmp(double a, double b)
{
     if (fabs(a-b) <= eps) return 0;
     return a<b?-1:1;
}
int n;
vi v;
vector<double> res;
bool ok(double dst, bool calc)
{
     if (calc) res.clear();
     int lst=0,cnt=0;
     while (lst < sz(v)) {
          double pos = v[lst]+dst;
          if (calc) res.push_back(pos);
          pos += dst;
          lst = lower_bound(all(v), pos)-v.begin();
          if (dcmp(pos+eps,v[lst]) == 0) ++lst;
          if (++cnt > 3) return 0;
     }
     return 1;
}
int main()
{

#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif


     cin >> n;
     v.resize(n);
     rep(i,n) cin >> v[i];
     sort(all(v));
     double st=0, en = 1e10;
     int cnt = 100;
     while (dcmp(st,en) < 0 && cnt--) {
          double mid = (st+en)/2.0;
          if (ok(mid,0))
               en = mid;
          else
               st = mid;
     }
     ok(en,1);
     printf("%.7lf\n",en);
     rep(i,3) printf("%.7lf ",res[i]);

     return 0;
}
