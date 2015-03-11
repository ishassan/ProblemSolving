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

struct rect{
    int x1,y1,x2,y2;
};

int n;
map<int,int> mapp;
vector<rect> v;
int id;
void gcompress(){
    for(pii p : mapp){
        mapp[p.first] = id++;
    }
    rep(i,n){
        v[i].x1 = mapp[v[i].x1];
        v[i].x2 = mapp[v[i].x2];
        v[i].y1 = mapp[v[i].y1];
        v[i].y2 = mapp[v[i].y2];
    }
}
ll msk[300][300];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
void ff(int x, int y, ll cur){
    msk[x][y]=-1;
    rep(d,4){
        int ni = x + di[d];
        int nj = y + dj[d];
        if(ni < 0 || nj < 0 || ni >= id || nj >= id || msk[ni][nj] != cur) continue;
        ff(ni,nj, cur);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >>n && n){
        mem(msk,0);
        mapp.clear();
        v.clear(); v.resize(n);
        id=1;
        rep(i,n){
            cin >> v[i].x1>> v[i].y1>> v[i].x2>> v[i].y2;
            mapp[v[i].x1],mapp[v[i].x2],mapp[v[i].y1],mapp[v[i].y2];
        }
        gcompress();
        rep(k,n){
            repa(x,v[k].x1, v[k].x2-1,1){
                repa(y,v[k].y2, v[k].y1-1, 1){
                    msk[x][y] |= (1LL << k);
                }
            }
        }
        int res=0;
        rep(x,id){
            rep(y,id){
                if(msk[x][y] >= 0){
                    ff(x,y,msk[x][y]);
                    ++res;
                }
            }
        }
        cout << res << "\n";

    }


    return 0;
}

