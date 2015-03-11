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

ll md, n;
ll memo[(1 << 18) + 10][102];
vi v;
ll DP(int bit, int mod)
{
    if(__builtin_popcount(bit) == sz(v)) return mod == 0;
    ll &m = memo[bit][mod];
    if(m != -1) return m;
    set<int> vis;
    m = 0;
    rep(i, sz(v)) {
        if((bit >> i) & 1 || (bit==0 && v[i]==0) || vis.count(v[i])) continue;
        m += DP(bit | (1<<i), (mod*10+v[i])%md);
        vis.insert(v[i]);
    }
    return m;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    cin >> n >> md;
    ll cpn = n;
    while(cpn) {
        v.push_back(cpn % 10);
        cpn /= 10;
    };
    mem(memo, -1);
    cout << DP(0,0);
    
    return 0;
}