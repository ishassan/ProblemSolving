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

double memo[1000002];
int vis[1000002];
int visID=1;
int n,d,s,a;
double DP(int n){
    if(n == 1) return d+a+s;
    double& m = memo[n];
    if(vis[n] == visID) return m;
    vis[n]=visID;
    if((n&1)==0)
        return m = DP(n/2)+d;
    return m = 0.5*(DP(n+1)+a) + 0.5*(DP(n-1)+s);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    while(tst--){
        cin >> n >> d >> s >> a;
        ++visID;
        printf("%.3lf\n",DP(n));
    }

    return 0;
}

