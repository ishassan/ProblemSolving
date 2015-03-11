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


int n,m,k;
int pop[20];
vector<vector<pii> > adj;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
      freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    while(tst--){
        cin >> n >> m >> k;
        adj.clear();
        adj.resize(n);
        rep(i,n) cin >> pop[i];
        rep(i,m){
            int a,b,c;
            cin >> a >> b >> c; --a,--b;
            adj[a].push_back(mp(c,b));
            adj[b].push_back(mp(c,a));
        }
        int mx=0;
        for (int i = 1; i < (1<<n); ++i) {
            int bit = 1, ans=0,cst=0;
            priority_queue<pii, vector<pii>, greater<pii> > q;
            rep(j,sz(adj[0])){
                int nxt = adj[0][j].second;
                if((i>>nxt)&1) q.push(adj[0][j]);
            }
            while(q.size()){
                pii p = q.top();
                q.pop();
                if((bit>>p.second) & 1) continue;
                if(p.first+cst > k) break;
                bit |= (1<<p.second);
                cst += p.first;
                ans += pop[p.second];
                int cur = p.second;
                rep(j,sz(adj[cur])){
                    pii nxt = adj[cur][j];
                    if(((i>>nxt.second)&1) && !((bit>>nxt.second)&1))
                        q.push(nxt);
                }
            }
            if(cst <= k){
                mx = max(mx,ans);
            }
        }
        cout << mx+pop[0] << "\n";
    }

    return 0;
}

