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

int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
const int SIZE=1005;
const ll OO = 1LL<<62;
int cstarr[300];
char g[SIZE][SIZE];
int n,h,w;
ll dist[SIZE][SIZE];

ll DijkstraWithHeap(int srci, int srcj){
    rep(i,h+2) fill(dist[i], dist[i]+w+2, OO);
    dist[srci][srcj]=0;
    priority_queue<pair<ll,pii>,vector<pair<ll,pii> >, greater<pair<ll,pii>> > q;
    q.push(mp(0LL,mp(srci,srcj)));
    while(q.size()){
        int curi = q.top().second.first;
        int curj = q.top().second.second;
        ll cst = q.top().first;
        q.pop();
        if(curi >= h || curi < 0 || curj >= w || curj < 0)
            return cst;
        if(cst != dist[curi][curj])
            continue;

        rep(d,4){
            int ni = curi + di[d];
            int nj = curj + dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w){
                q.push(mp(cst, mp(ni,nj)));
                continue;
            }
            char c = g[ni][nj];
            if(dist[ni][nj] > dist[curi][curj]+cstarr[c]){
                dist[ni][nj] = dist[curi][curj]+cstarr[c];
                q.push(mp(dist[ni][nj], mp(ni,nj)));
            }
        }
    }
    return OO;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif


    int tst;
    cin >> tst;
    while(tst--){
        mem(cstarr,0);
        int k;
        char c;
        cin >> k >>w >> h;
        while(k--){
            cin >> c;
            cin >> cstarr[c];
        }
        int srci,srcj;
        rep(i,h) {
            cin >> g[i];
            rep(j,w) if(g[i][j]=='E') srci=i,srcj=j;
        }
        cout << DijkstraWithHeap(srci,srcj) << "\n";

    }
    return 0;
}

