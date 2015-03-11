#include <bits/stdc++.h>
#include <ext/numeric>

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
using namespace __gnu_cxx;

const int mod = 1000000;
struct mul{
    const int mod = 1000000;
    vector<vector<ll> > operator()(const vector<vector<ll> >& m1, const vector<vector<ll> >& m2){
        int r1 = m1.size(), c1 = m1[0].size();
        int r2 = m2.size(), c2 = m2[0].size();
        vector<vector<ll> > res = vector<vector<ll> >(r1, vector<ll>(c2, 0));
        rep(i,r1) rep(j,c2) rep(k,c1){
            res[i][j] += m1[i][k] * m2[k][j];
            res[i][j] %= mod;
        }
        return res;
    }
};

vector<vector<ll> > identity_element(const mul&){
    vector<vector<ll> > res = {{1,0},{0,1}};
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    ll n,c1,c2;
    while(cin >> n >> c1 >> c2){
        vector<vector<ll> > mat={{c1%mod, 1},{c2%mod,0}};
        vector<vector<ll> > res = power(mat, n/5, mul());
        sstr ss; string str;
        ss << res[0][0];
        ss >> str;
        str = string(6-sz(str),'0') + str;
        cout << str << "\n";
    }
    return 0;
}

