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

const int SIZE = 10003;
int siz[2][SIZE],n[2];
char tp[2][SIZE];
vector<vi> adj[2];
const int mod[2] = {999999937, 1e9+7};
const int base = 300;

struct cmp{
    bool operator()(const valarray<ll>& a, const valarray<ll>& b)const{
        if(a[0] == b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
};
map<valarray<ll>, int, cmp> htosz;
int mx=0;

//valarray = pair<ll,ll> for double hash
valarray<ll> hashf(int idx, bool treeidx, bool docmp){
    siz[treeidx][idx]++;
    valarray<ll> res={tp[treeidx][idx],tp[treeidx][idx]}; //type
    res *= base; res[0] %=mod[0]; res[1] %= mod[1];
    res += sz(adj[treeidx][idx]); //sz of child
    res[0]%=mod[0]; res[1]%=mod[1];
    int i = 0;
    repi(it,adj[treeidx][idx]){
        res *= hashf(*it, treeidx, docmp); //hash every child
        res += base;
        res[0]%=mod[0]; res[1]%=mod[1];
        siz[treeidx][idx] += siz[treeidx][*it];
        ++i;
    }

    if(!docmp)htosz[res] = siz[treeidx][idx];
    else{
        if(htosz.count(res)) mx = max(mx, siz[treeidx][idx]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);
#endif

    int tst,p;
    cin >> tst;
    while(tst--){
        htosz.clear();
        mx = 0;
        cin >> n[0] >> n[1];
        mem(siz,0);
        adj[0] = vector<vi>(n[0]);
        adj[1] = vector<vi>(n[1]);
        rep(k,2){
            rep(i,n[k]){
                cin >> tp[k][i] >> p;
                if(i) adj[k][p].push_back(i);
            }
        }
        hashf(0,0,0);
        hashf(0,1,1);
        cout << mx << "\n";
    }

    return 0;
}

