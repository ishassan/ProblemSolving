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

vi v,v2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n,m,k;
    cin >> n >> m >> k;
    rep(i,n) cin >> k, v.push_back(k);
    rep(i,m) cin >> k, v2.push_back(k);
    if(n > m){cout << "YES\n"; return 0;}
    sort(rall(v));
    sort(rall(v2));
    repd(i,sz(v)-1,0,1){
        if(v[i] > v2[i]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

