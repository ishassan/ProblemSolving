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

ll cumr[1002],cumc[1002];
ll g[1002][1002];
ll resr[1000003],resc[1000003];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    ll n,m,k,p;
    while(cin >> n >> m >> k >> p){
        mem(cumr,0);
        mem(cumc,0);
        rep(i,n) rep(j,m){
            cin >> g[i][j];
            cumr[i] += g[i][j];
            cumc[j] += g[i][j];
        }

        priority_queue<ll> qr,qc;
        rep(i,n) qr.push(cumr[i]);
        rep(i,m) qc.push(cumc[i]);
        resr[0] = resc[0] = 0;
        repa(kk,1,k,1){
            ll curr = qr.top();
            resr[kk] = curr+resr[kk-1];
            curr -= p*m;
            qr.pop();
            qr.push(curr);

            ll curc = qc.top();
            resc[kk] = curc+resc[kk-1];
            curc -= p*n;
            qc.pop();
            qc.push(curc);
        }
        ll mx = -1LL<<60;
        repa(kk,0,k,1){
            ll res = resr[kk]+resc[k-kk]-(kk*(k-kk)*p);
            mx = max(mx, res);
        }
        cout << mx << "\n";
    }


    return 0;
}

