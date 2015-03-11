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

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

ll val[100002], clr[100002];
ll bestclr[200000];
vector<pair<ll, int> > toptwo;
ll OO = 1LL << 62;
int n;
inline void mysort()
{
    if(toptwo.front().first > toptwo.back().first)
        swap(toptwo.front(), toptwo.back());
}
void addTopTow(ll score, int c)
{
    if(toptwo.size() < 2) {
        toptwo.push_back(mp(score, c));
        return;
    }
    bool yes = 0;
    rep(i, 2)
    if(toptwo[i].second == c)
        yes = 1, toptwo[i].first = max(toptwo[i].first, score);
    if(yes) return;
    mysort();
    if(score > toptwo[0].first)
        toptwo[0] = mp(score, c);
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    int  q, a, b;
    scanf("%d%d", &n, &q);
    rep(i, n) scanf(LL, &val[i]);
    rep(i, n) scanf(LL, &clr[i]);
    while(q--) {
        scanf("%d%d", &a, &b);
        fill(bestclr, bestclr + n + 5, -OO);
        toptwo.clear();
        toptwo.push_back(mp(0LL, -n - 10));
        rep(i, n) {
            ll mx = -OO;
            if(bestclr[clr[i]] != -OO)
                mx = max(mx, bestclr[clr[i]] + a * val[i]);
            repi(it, toptwo) {
                if(it->second != clr[i])
                    mx = max(mx, it->first + b * val[i]);
            }
            bestclr[clr[i]] = max(bestclr[clr[i]], mx);
            addTopTow(bestclr[clr[i]], clr[i]);
        }
        mysort();
        printf(LL "\n", toptwo.back().first);
    }
    return 0;
}