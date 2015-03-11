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

ll c[4],n,m;
ll cntbus[1002],cnttro[1002];
ll solvebus(){
    ll res = 0;
    rep(i,n){
        res += min(cntbus[i]*c[0],c[1]);
    }
    return min(res,c[2]);
}
ll solvetro(){
    ll res = 0;
    rep(i,m){
        res += min(cnttro[i]*c[0],c[1]);
    }
    return min(res,c[2]);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    rep(i,4) cin >> c[i];
    cin >> n >> m;
    rep(i,n) cin >> cntbus[i];
    rep(i,m) cin >> cnttro[i];
    cout << min(solvebus() + solvetro(), c[3]);
    return 0;
}
