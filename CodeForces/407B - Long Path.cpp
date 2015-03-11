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

const int mod = 1000000007;
int n;
int nxt[1005];
ll memo[1005];
ll DP(int idx){
    if(idx == 0) return 0;
    ll& m = memo[idx];
    if(m != -1) return m;
    return m = (((2*DP(idx-1)+2-DP(nxt[idx-1]))%mod) + mod) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n){
        mem(memo,-1);
        rep(i,n) {
            cin >> nxt[i];
            nxt[i]--;
        }
        cout << DP(n) << "\n";
    }
    return 0;
}

