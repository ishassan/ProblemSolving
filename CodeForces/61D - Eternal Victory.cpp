#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

const int SIZE=100005;
const ll OO = 1LL<<60;
vector<vector<pair<ll,int> > > adjlst; //cst,node
int n;
ll dist[SIZE];
bool vis[SIZE];
ll DijkstraWithHeap(int src){
    fill(dist,dist+n,-OO);
    mem(vis,0);
    dist[src]=0LL;
    vis[src]=1;
    priority_queue<pair<ll,int>> q;
    q.push(mp(0LL,src));
    ll mx = -OO;
    while(q.size()){
        src = q.top().second;
        ll cst = q.top().first;
        mx = max(mx,cst);
        q.pop();
        if(cst != dist[src])
            continue;
        repi(it, adjlst[src]){
            int nxt = it->second;
            ll nxtc = it->first;
            if(!vis[nxt] && dist[nxt] < dist[src] + nxtc){
                dist[nxt] = dist[src] + nxtc;
                vis[nxt]=1;
                q.push(mp(dist[nxt],nxt));
            }
        }
    }
    return mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int a,b,c;
    cin >> n;
    adjlst.resize(n);
    ll res = 0;
    rep(i,n-1){
        cin >> a >> b >> c;
        --a,--b;
        adjlst[a].push_back(mp(c,b));
        adjlst[b].push_back(mp(c,a));
        res += 2*c;
    }
    res -= DijkstraWithHeap(0);
    cout << res;
    return 0;
}
