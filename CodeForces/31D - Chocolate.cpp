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

bool grid[205][205];
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int h, w, n;
    scanf("%d%d%d", &w, &h, &n);
    h*=2,w*=2;
    while(n--) {
        int x1, x2, y11, y2;
        scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
        x1 *= 2, x2 *= 2, y11 *= 2, y2 *= 2;
        repa(i, x1, x2, 1) {
            grid[h - y11][i] = 1;
            grid[h - y2][i] = 1;
        }
        repa(i, y11, y2, 1) {
            grid[h - i][x1] = 1;
            grid[h - i][x2] = 1;
        }
    }
//     repd(i, h,0,1) {
//         rep(j, w)
//         cout << grid[i][j];
//         cout << endl;
//     }

    vi v;
    rep(y, h) {
        rep(x, w) {
            if(grid[y][x]) continue;
            int xsz = 0, ysz = 0;
            repa(xx, x, w - 1, 1)
            if(grid[y][xx]) break;
            else xsz++;

            repa(yy, y, h - 1, 1)
            if(grid[yy][x]) break;
            else ysz++;

            rep(yy, ysz)
            rep(xx, xsz) {
                grid[y + yy][x + xx] = 1;
            }
            xsz = (xsz + 1) / 2;
            ysz = (ysz + 1) / 2;
            v.push_back(xsz * ysz);
        }
    }
    sort(all(v));
    rep(i, sz(v)) cout << v[i] << " ";
    return 0;
}