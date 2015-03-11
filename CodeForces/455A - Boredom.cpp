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
#define pii pair<ll,ll>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int freq[100005];
ll memo[100005];
vector<pii> v;
int n;
ll DP(int idx){
    if(idx == sz(v)) return 0;
    ll& m = memo[idx];
    if(m != -1) return m;

    m = DP(idx+1);
    int nxt=idx+1;
    if(idx+1 < sz(v) && v[idx+1].first-1==v[idx].first)
        ++nxt;
    m = max(m, DP(nxt) + v[idx].second*v[idx].first);
    return m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int x;
    while(cin >> n){
        mem(freq,0);
        mem(memo,-1);
        v.clear();
        rep(i,n) {
            cin >> x;
            freq[x]++;
        }
        repa(i,1,100000,1){
            if(freq[i])
                v.push_back(mp(i, freq[i]));
        }
        cout << DP(0) << "\n";

    }
    return 0;
}

