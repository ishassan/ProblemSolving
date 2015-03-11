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

const ll mod = 10000000000007LL;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif


//    n(n-1)(n-2)(n-3)(n-r+1) => n(n-1)(n-2)(n-3)(n-r+1)(n-r)
    int tst;
    cin >> tst;

    repa(cs, 1, tst, 1){
        int n,mn,mx;
        cin >> n >> mn >> mx;
        n *= n;
        ll nck = 1;
        ll sum = 0;
        for (int i = 1; i <= mx; ++i) {
            nck *= (n-i+1);
            nck %= mod;
            if(i>=mn){
                sum += nck;
                sum %= mod;
            }
        }
        cout <<"Case " << cs<<": " << sum <<"\n";
    }

    return 0;
}
