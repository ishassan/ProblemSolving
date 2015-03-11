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

int n;
const int SIZE = 3000;
struct DisjointSets {
    int parent[SIZE], rank[SIZE], componentsCnt;
    DisjointSets(int n) {
        memset(rank, 0, sizeof rank);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        componentsCnt = n;
    }
    int find(int e) {
        return parent[e] == e ? e : parent[e] = find(parent[e]);
    }
    bool join(int e1, int e2) {
        int p1 = find(e1), p2 = find(e2);
        if(p1 == p2)
            return 0;
        if(rank[p1] == rank[p2])
            rank[p1]++;
        if(rank[p2] > rank[p1])
            swap(p1, p2);
        parent[p2] = p1;
        componentsCnt--; // new components get merged
        return 1;
    }
};
struct edge{
    int f, t,c;
    edge(){}
    edge(int f, int t, int c):f(f),t(t),c(c){}
    bool operator<(const edge& e)const{
        if(c < e.c) return 1;
        if(c > e.c) return 0;
        return mp(f,t) < mp(e.f,e.t);
    }
};

int mat[2003][2003];
int dist[2003][2003];
vector<edge> ed,sol;
vector<vi> adj;

void dfs(int st, int prev, int cur, int cst){
    dist[st][cur] = cst;
    rep(i,sz(adj[cur])){
        int nxt = adj[cur][i];
        if(nxt == prev) continue;
        dfs(st,cur,nxt,cst+dist[cur][nxt]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif

    string en;
    while(cin >> n){
        mem(dist,127);
        DisjointSets dis(n);
        ed.clear(); sol.clear();
        adj.clear();
        adj.resize(n);
        rep(i,n) {
            dist[i][i] = 0;
            rep(j,n) {
                cin >> mat[i][j];
                ed.push_back(edge(i,j,mat[i][j]));

            }
        }

        //MST to add n-1 edges
        sort(all(ed));
        rep(i,sz(ed)){
            if(dis.join(ed[i].f, ed[i].t)){
                adj[ed[i].f].push_back(ed[i].t);
                adj[ed[i].t].push_back(ed[i].f);
                dist[ed[i].f][ed[i].t] = dist[ed[i].t][ed[i].f] = ed[i].c;
                sol.push_back(ed[i]);
                // if(sz(sol) == n-1) break;
            }
        }

        // all pair shortest path
        rep(i,n){
            dfs(i,-1,i,0);
        }

        //choosing n-th edge
        int bsti=0,bstj=1,cst=1<<27;
        rep(i,n) repa(j,i+1,n-1,1){
            if(mat[i][j] < dist[i][j] && mat[i][j] < cst){
                bsti = i, bstj = j;
                cst = mat[i][j];
            }
        }

        sol.push_back(edge(bsti,bstj,min(cst, 1000000)));
        cout << en;
        en = "\n";
        rep(i,sz(sol)){
            cout << sol[i].f+1 << " " << sol[i].t+1 << " " << sol[i].c << "\n";
        }

    }


    return 0;
}
