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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int arr[1005][1005];
int cntr[1005];
vector<pair<int, pii> > res;
int main()
{
    int n, x, y;
    scanf("%d", &n);
    rep(i, n - 1) {
        scanf("%d%d", &x, &y);
        arr[x][y] = 1;
        cntr[x]++;
    }
    int cntEmpty = 1;
    repa(i, 1, n, 1){
        if(cntr[i]==0) {
            if(i == cntEmpty) {
                ++cntEmpty;
                continue;
            }
            swap(arr[i],arr[cntEmpty]);
            swap(cntr[i],cntr[cntEmpty]);
            res.push_back(mp(1, mp(i, cntEmpty++)));
        }
    }
    int col = 1;
    repa(i, cntEmpty, n, 1) {
        repa(j,col,n,1){
            if(arr[i][j]==0) continue;
            if(j==col){
                ++col;
                continue;
            }
            repa(k,i,n,1) swap(arr[k][col],arr[k][j]);
            res.push_back(mp(2, mp(col, j)));
            ++col;
        }
    }

    printf("%d\n", sz(res));
    rep(i, sz(res)) {
        printf("%d %d %d\n", res[i].first, res[i].second.first, res[i].second.second);
    }
    return 0;
}
