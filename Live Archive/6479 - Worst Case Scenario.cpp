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
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int w,h;
char g[200][200];

int diri[]={-1,0,1,0};
int dirj[]={0,1,0,-1};
bool vis[102][102][4];
void affect(int r, int c, int parr, int parc){
    if(g[r][c] == 'D'){
        rep(d,4){
            int nr = r + diri[d];
            int nc = c + dirj[d];
            if(nr < 0 || nc < 0 || nr >= h || nc >= w || g[nr][nc]=='X' || vis[r][c][d]) continue;
            if(nr == parr && nc == parc) continue;
            vis[r][c][d]=1;
            affect(nr,nc, r,c);
        }
    }
    else ++g[r][c];
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
        cin >> w >> h;
        rep(i,h) cin>>g[i];
        int q,r,c;
        cin >> q;
        while(q--){
            cin >> c >> r;
            mem(vis,0);
            affect(r,c,-1,-1);
        }
        rep(i,h)cout<<g[i]<<"\n";
    }
    return 0;
}

