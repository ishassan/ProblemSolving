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
//0 1
//2 3
int g[1002][1002];
int memo[3][4][1002][1002]; //d1: reach dist from i or j or any, d2: each index represent dist place (4 corners)
int n,m;
int tari,tarj,di,dj;
inline void setparams(int goalIndex){
    if(goalIndex == 0){
        tari = tarj = 0;
        di = dj = -1;
    }
    else if(goalIndex == 1){
        tari = 0, tarj = m-1;
        di = -1, dj = 1;
    }
    else if(goalIndex == 2){
        tari = n-1, tarj = 0;
        di = 1, dj = -1;
    }
    else if(goalIndex == 3){
        tari = n-1, tarj = m-1;
        di = 1, dj = 1;
    }
}

int DPFromij(int i, int j, int goalIndex, int movi){
    if(i >= n || i < 0 || j >= m || j < 0) return -1<<28;
    if(i == tari && j == tarj) return g[i][j];
    int& ref = memo[movi][goalIndex][i][j];
    if(ref != -1) return ref;

    if(movi == 0){
        return ref = DPFromij(i,j+dj,goalIndex,2)+g[i][j];
    }
    else if(movi == 1){
        return ref = DPFromij(i+di,j,goalIndex,2)+g[i][j];
    }

    ref = DPFromij(i+di, j, goalIndex, movi);
    ref = max(ref, DPFromij(i,j+dj, goalIndex, movi) );
    ref += g[i][j];
    return ref;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n >> m){
        mem(memo,-1);
        rep(i,n) rep(j,m) cin >>g[i][j];
        int mx=0;
        rep(i,n) rep(j,m) rep(fromi1,2){
            int fromi2 = !fromi1;
            int before1,before2;

            setparams(0);
            before1 = DPFromij(i,j,0,fromi1) - g[i][j];
            setparams(2);
            before2 = DPFromij(i,j,2,fromi2) - g[i][j];

            int calc = 0;
            if(!fromi1){ // p1 from left, p2 from down
                int p1r,p2u;
                setparams(3);
                p1r = DPFromij(i,j+dj,3,2);
                setparams(1);
                p2u = DPFromij(i+di,j,1,2);
                calc = p1r+p2u;
            }
            else{ //p1 from up, p2 from left
                int p1d, p2r;
                setparams(3);
                p1d = DPFromij(i+di,j,3,2);
                setparams(1);
                p2r = DPFromij(i,j+dj,1,2);
                calc = p1d+p2r;
            }
            calc += before1+before2;
            mx = max(mx, calc);
        }
        cout << mx << "\n";
    }


    return 0;
}

