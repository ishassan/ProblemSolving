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

//0 down, 1 up
vector<vector<int> > g[2];
int n,m;
struct state{
    int idx, mode, cst;
};
bool vis[10002][2];
int BFS(int s, int t){
    deque<state> q;
    q.push_back({s,0,0});
    q.push_back({s,1,0});
    while(q.size()){
        state st = q.front();
        q.pop_front();
        if(st.idx == t) return st.cst;
        vis[st.idx][st.mode] = 1;
        rep(i,sz(g[st.mode][st.idx])){
            int nxt = g[st.mode][st.idx][i];
            if(vis[nxt][st.mode]) continue;

            q.push_front({nxt,st.mode,st.cst});
        }
        rep(i,sz(g[!st.mode][st.idx])){
            int nxt = g[!st.mode][st.idx][i];
            if(vis[nxt][!st.mode]) continue;
            q.push_back({nxt,!st.mode,st.cst+1});
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif


    int a,b;

    cin >> n >> m;
    g[0].resize(n+5);
    g[1].resize(n+5);
    rep(i,m){
        cin >> a >> b;
        g[1][a].push_back(b);
        g[0][b].push_back(a);
    }

    cin >> a >> b;
    cout << BFS(a,b);
    return 0;
}

