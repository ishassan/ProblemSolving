#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int n,k;
const int mod = 1000000007;
ll memo[2002][2002];

ll DP(int idx, int lst){
    if(idx == k) return 1;
    ll& m = memo[idx][lst];
    if(m != -1) return m;

    m = 0;
    for (int i = 1; i*lst <= n; ++i) {
        m += DP(idx+1, i*lst);
        if(m > mod) m%=mod;
    }
    return m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    cin >> n >> k;
    mem(memo,-1);
    cout << DP(0,1);
    return 0;
}

