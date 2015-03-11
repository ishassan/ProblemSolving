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
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
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
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;

vector<string> g,blk[2];
set<vector<string> > vis;
void rotate(vector<string>& v, vector<string>& res){
    res = vector<string>(v[0].size(), string(sz(v),' '));
    rep(i,sz(res))
        rep(j,sz(res[i]))
            res[i][j] = v[j][sz(res)-i-1];
}
bool ok(int a, int b){
    repa(i,0,sz(g)-1,a){
        repa(j,0,sz(g[0])-1,b){
            blk[0]=vector<string>(a,string(b,' '));
            rep(ii,a) rep(jj,b)
                    blk[0][ii][jj]=g[i+ii][j+jj];
            set<vector<string> >sub;
            sub.insert(blk[0]);
            rep(k,3){
                rotate(blk[k&1],blk[!(k&1)]);
                sub.insert(blk[!(k&1)]);
            }
            int siz = sz(vis);
            vis.insert(all(sub));
            if(siz+sz(sub)!=sz(vis)) return 0;
        }
    }
    return 1;
}
int main()
{   
    int A,B;
    cin >> A >> B;
    g = vector<string>(A);
    rep(i,A) cin >> g[i];
    int area=1<<27,mna=1<<27,mnb=1<<27,res=0;
    repa(a,1,A,1){
        if(A%a) continue;
        repa(b,1,B,1){
            if(B%b || !ok(a,b)) continue;
            if(area>a*b||(area==a*b && mna>a )){
                area=a*b, mna=a,mnb=b;
            }
            ++res;
            vis.clear();
        }
    }
    printf("%d\n%d %d",res,mna,mnb);
   
    return 0;
}