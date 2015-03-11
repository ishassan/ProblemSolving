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

vector<vector<int> > g, par;
vi age;
int n,m,I;

int memo[502];
int vis[502], visID;
int getMin(int cur){
    if(sz(par[cur]) == 0) return 1<<29;
    int& m = memo[cur];
    if(vis[cur] == visID) return m;
    vis[cur] = visID;
    m = 1<<29;
    rep(i,sz(par[cur])){
        int pi = par[cur][i];
        m = min(m, age[pi]);
        m = min(m, getMin(pi));
    }
    return m;
}

void repLow(int cur, int from, int to, vector<vi>& nwpar){
    rep(i,sz(g[cur])){
        int ch = g[cur][i];
        replace(all(nwpar[ch]), from, to);
    }
}
void repHi(int cur, int from, int to, vector<vi>& nwg){
    rep(i,sz(par[cur])){
        int pi = par[cur][i];
        replace(all(nwg[pi]), from, to);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif

    while(cin >> n >> m >> I){
        int a,b;
        par = vector<vi>(n);
        g = vector<vi>(n);
        age = vi(n);
        rep(i,n) cin >> age[i];
        rep(i,m){

            cin >> a >> b; --a,--b;
            g[a].push_back(b);
            par[b].push_back(a);
        }
        char c;
        rep(k,I){
            cin >> c;
            if(c == 'T'){
                cin >> a >> b; --a,--b;
                vector<vi> nwg=g, nwpar=par;
                repLow(a, a, 1000,nwpar);
                repLow(b, b, a, nwpar);
                repLow(a, 1000, b, nwpar);

                repHi(a, a, 1000, nwg);
                repHi(b, b, a,nwg);
                repHi(a, 1000, b,nwg);

                swap(nwg[a], nwg[b]);
                swap(nwpar[a],nwpar[b]);
                g = nwg, par = nwpar;
            }
            else{
                cin >> a;--a;
                ++visID;
                int mn = getMin(a);
                if(mn == 1<<29) cout <<"*\n";
                else cout << mn << "\n";
            }
        }
    }

    return 0;
}

