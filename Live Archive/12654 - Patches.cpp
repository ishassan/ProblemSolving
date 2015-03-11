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

vi d;
int n,p1,p2;
int memo[1002];
int vis[1002], visID;
int DP(int idx){
    if(idx == n) return 0;
    int& m = memo[idx];
    if(vis[idx] == visID) return m;
    vis[idx] = visID;
    int nxt1 = upper_bound(all(d),d[idx]+p1) - d.begin();
    int nxt2 = upper_bound(all(d),d[idx]+p2) - d.begin();
    return m = min(DP(nxt1) + p1, DP(nxt2) + p2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    int l;
    while(cin >> n >> l >> p1 >> p2){
        if(p1 > p2) swap(p1,p2);
        ++visID;
        d.clear();
        d.resize(n);
        rep(i,n) cin >> d[i];
        sort(all(d));
        cout << DP(0) << "\n";
    }


    return 0;
}

