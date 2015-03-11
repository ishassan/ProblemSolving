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

// DP Counting
ll n[2];
int siz[2];
ll memo[60][2][2];
ll DP(int idx, bool nidx, bool isless){
    if(idx == siz[nidx]) return 0;
    ll& m = memo[idx][nidx][isless];
    if(m != -1) return m;
    int bi = siz[nidx]-idx-1;
    if(isless){
        m = DP(idx+1, nidx, isless);
        m += DP(idx+1, nidx, isless) + (1LL<<bi);
        return m;
    }
    if((n[nidx]>>bi)&1){
        m = DP(idx+1,nidx,1);
        m += DP(idx+1,nidx,isless);
        ll upper =(1LL<<(bi+1))-1;
        upper = upper & n[nidx];
        ll lower = 1LL<<bi;
        m += upper-lower+1;
    }
    else
        m = DP(idx+1,nidx,isless);
    return m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n[0] >> n[1]){
        n[0]--;
        siz[0] = n[0]==0?0:(log2(n[0])+1);
        siz[1] = n[1]==0?0:(log2(n[1])+1);
        mem(memo,-1);
        cout << DP(0,1,0) - DP(0,0,0) << "\n";
    }

    return 0;
}

