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

vector<ll> v,res;
bool rem[100004];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie();
    int n,k;
    cin >> n >> k;
    v.resize(n);
    rep(i,n) cin >> v[i];
    sort(all(v));
    rep(i,n){
        if(rem[i]) continue;
        ll num = v[i]*k;
        int idx = lower_bound(all(v), num) - v.begin();
        if(idx < sz(v) && v[idx]==num)
            rem[idx]=1;
        res.push_back(v[i]);
    }
    cout << sz(res);
    return 0;
}