#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

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

int n;
int X1[1002], Y1[1002], X2[1002], Y2[1002];
map<int, int> xs, ys;
int xsize[4010], ysize[4010];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char arr[5] = "UDRL";

int compress(map<int,int>& m, int siz[]){
    int lst = -2e9;
    int nxt=0;
    repi(it,m){
        int cur = it->first;
        if(lst+1 != cur){
            siz[nxt++] = cur-lst-1;
        }
        siz[nxt] = 1;
        it->second = nxt++;
        lst = cur;
    }
    return nxt+1;
    
}

int h,w;
int grid[4020][4020];

void ff(int x, int y){
    if(x < 0 || y < 0 || x >= w || y >= h || grid[x][y]) return;
    grid[x][y] = 2;
    rep(d,4){
        ff(x+dx[d], y+dy[d]);
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int x=0,y=0,d;
    scanf("%d",&n);
    rep(i,n){
        char c;
        scanf(" %c%d",&c,&d);
        int k = find(arr,arr+4,c)-arr;
        int nx = x+dx[k]*d;
        int ny = y+dy[k]*d;
        xs[x],ys[y],xs[nx],ys[ny];
        X1[i] = min(x,nx), Y1[i] = min(y,ny);
        X2[i] = max(x,nx), Y2[i] = max(y,ny);
        x=nx,y=ny;
    }
    h = compress(ys,ysize), w = compress(xs,xsize);
    rep(i,n){
        int xe=xs[X2[i]];
        int ye=ys[Y2[i]];
        
        repa(x,xs[X1[i]],xe,1){
            repa(y,ys[Y1[i]],ye,1){
                grid[x][y] = 1;
            }
        }
    }
    
    ff(0,0);
    ll res = 0;
    rep(x,w){
        rep(y,h){
            if(grid[x][y] != 2)
                res += xsize[x]*1LL*ysize[y];
        }
    }
    
    cout << res;

    return 0;
}