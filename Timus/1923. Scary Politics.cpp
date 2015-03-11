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

int n,M;
char g[55][55];
int mrk[55][55];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void ff(int mrkid, char newid){
    bool vis[55][55]={0};
    queue<pii> q;
    rep(i,n){
        rep(j,M){
            if(mrk[i][j]==mrkid){
                q.push(mp(i,j));
                vis[i][j]=1;
            }
        }
    }
    while(q.size()){
        pii p = q.front();
        q.pop();
        rep(d,4){
            int ni = p.first + di[d];
            int nj = p.second  + dj[d];
            if(ni < 0 || nj < 0 || ni >= n || nj >= M) continue;
            if(g[ni][nj] != newid || vis[ni][nj]) continue;
            if(mrk[ni][nj] != -1 && mrk[ni][nj]^mrkid) continue;
            vis[ni][nj]=1;
            q.push(mp(ni,nj));
            mrk[ni][nj]=mrkid;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    cin >> n >> M;
    rep(i,n) cin >> g[i];
    mem(mrk,-1);
    mrk[n-1][0] = 0;
    mrk[0][M-1] = 1;
    ff(0,g[n-1][0]);
    ff(1,g[0][M-1]);
    int x;
    cin >> x;
    rep(i,x){
        char newid;
        cin >> newid;
        ff(i&1,newid);
    }
    int sum[2]={0,0};
    rep(i,n){
        rep(j,M){
            if(mrk[i][j]>-1)
                sum[mrk[i][j]&1]++;
        }
    }
    cout << sum[0] << "\n" << sum[1]<<"\n";
    return 0;
}

