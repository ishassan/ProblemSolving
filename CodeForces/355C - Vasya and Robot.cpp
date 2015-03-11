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

int n,l,r,ql,qr;
ll w[100002],cum[100002];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin >> n>>l>>r>>ql>>qr;
    cum[0]=0;
    rep(i,n) 
    {
        cin >> w[i];
        cum[i+1]=cum[i]+w[i];
    }
    
    ll res = 1e18;
    
    repa(tl,0,n,1){
        int tr = n-tl;
        ll x = cum[tl]*l + (cum[n]-cum[tl])*r;
        if(tl-tr>1)
            x += (tl-tr-1)*ql;
        else if(tr-tl>1)
            x += (tr-tl-1)*qr;
        res = min(res,x);
    }
    cout << res;
    return 0;
}
