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

int h[2],w[2];
bool g[2][102][102];
bool res[102][102];
vector<pii> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    repa(T,1,tst,1){
        v.clear();
        rep(k,2){
            cin >> h[k]>>w[k];
            rep(i,h[k]) rep(j,w[k]) {
                cin >> g[k][i][j];
                if(k==0){
                    res[i][j] = g[k][i][j];
                    if(g[k][i][j]) v.push_back(mp(i,j));
                }
            }
        }

        int org = h[1]/2;
        rep(k,sz(v)){
            pii p = v[k];
            int sti = p.first-org, stj = p.second-org;
            for (int i = sti, ii=0; ii < h[1]; ++i,++ii) {
                for (int j = stj, jj=0; jj < w[1]; ++j,++jj) {
                    if(i < 0 || j < 0 || i>= h[0] || j>=w[0]) continue;
                    res[i][j] |= g[1][ii][jj];
                }
            }
        }

        printf("Case %d:\n",T);
        rep(i,h[0]){
            rep(j,w[0]){
                printf("%d%c",res[i][j]," \n"[j+1==w[0]]);
            }
        }


    }


    return 0;
}

