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

vector<vector<pii> > adj;
int deg[50];
vi res;
int vis[50], visID=1;
void euler(int src){
    rep(i,sz(adj[src])){
        int nxt = adj[src][i].second;
        int id = adj[src][i].first;
        if(vis[id] == visID) continue;
        vis[id] = visID;
        euler(nxt);
        res.push_back(id);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int f,t,s;
    while(cin >> f >> t && (f||t)){
        mem(deg,0);
        ++visID;
        adj = vector<vector<pii> >(50);
        int src = min(f,t);
        do{
            cin >> s;
            adj[f].push_back(mp(s,t));
            adj[t].push_back(mp(s,f));
            deg[f]^=1;
            deg[t]^=1;
        }while(cin >> f >> t && (t || f));
        if(find(deg,deg+50,1) < deg+50){
            puts("Round trip does not exist.\n");
            continue;
        }
        rep(i,sz(adj))   sort(all(adj[i]));
        res.clear();
        euler(src);
        repd(i,sz(res)-1,0,1) printf("%d%c", res[i], " \n"[i==0]);
        printf("\n");
    }

    return 0;
}
