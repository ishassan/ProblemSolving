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

const double OO = 1e18;
const double eps = 1e-10;
const ll one = 1000000LL;
int n, t;
struct problem {
    ll scsmall, sclarge, tsmall, tlarge;
    double pfail;
    bool operator <(const problem &st)const {
        double t1 = tlarge * (1.0 - pfail) * st.pfail + (tlarge + st.tlarge) * (1.0 - st.pfail);
        double t2 = st.tlarge * (1.0 - st.pfail) * pfail + (st.tlarge + tlarge) * (1.0 - pfail);
        return t1 < t2;
    }
};

int dcmp(double a, double b)
{
    if(fabs(a - b) < eps) return 0;
    return a < b ? -1 : 1;
}
void update(pair<ll, double> &m, pair<ll, double> r)
{
    if(r.first > m.first || (r.first == m.first && dcmp(r.second, m.second) < 0)) m = r;
}
vector<problem> v;
pair<ll, double> memo[1002][1600];
pair<ll, double> DP(int siz, int remt)
{
    if(remt < 0) return mp((ll) - OO, -OO);
    if(siz == 0) return remt ? mp((ll) - OO, -OO) : mp(0LL, 0.0);
    int idx = siz - 1;
    pair<ll, double> &m = memo[idx][remt];
    if(m.first != -1) return m;

    m = DP(siz - 1, remt);

    pair<ll, double> r = DP(siz - 1, remt - v[idx].tsmall);
    r.first += v[idx].scsmall * one;
    r.second += v[idx].tsmall;
    update(m, r);

    r = DP(siz - 1, remt - v[idx].tsmall - v[idx].tlarge);
    r.second += v[idx].tsmall;
    r.first += v[idx].scsmall * one + one * v[idx].sclarge * (1.0 - v[idx].pfail + eps);

    r.second = r.second * (v[idx].pfail) + remt * (1.0 - v[idx].pfail);
    update(m, r);

    return m;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif
// 395.6876580000 98.4357291285

    ios::sync_with_stdio(0);
    cin >> n >> t;
    v.resize(n);
    double d;
    rep(i, n) {
        cin >> v[i].scsmall >> v[i].sclarge >> v[i].tsmall >> v[i].tlarge >> v[i].pfail;
    }
    sort(all(v));
    mem(memo, -1);
    pair<ll, double> m = mp(0LL, 0.0);
    repa(i, 1, t, 1) {
        pair<ll, double> r = DP(n, i);
        update(m, r);

    }

    printf("%.10lf %.10lf\n", (1.0 * m.first) / one ,  m.second);
    return 0;
}