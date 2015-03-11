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
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
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
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
#define itr(A,B) typeof(B) A = B
typedef long long ll;
using namespace std;


void toBase(ll n, ll b, vi& v){
    while(n){
        v.push_back(n%b);
        n /= b;
    }
    reverse(all(v));
}

ll toTen(ll b,const vi& v){
    ll res=0;
    ll p=1;
    for (int i = sz(v)-1; i >= 0; --i) {
        res += p*v[i];
        p *= b;
    }
    return res;
}

void calc(const vi& x,const vi& y, ll b, vi& res){
    int i = sz(x)-1, j = sz(y)-1;
    while(i >=0 || j>=0){
        if(i < 0)
            res.push_back(y[j--]);
        else if(j < 0)
            res.push_back(x[i--]);
        else
            res.push_back((x[i--] + y[j--])%b);
    }
    reverse(all(res));
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int n;
    scanf("%d",&n);
    while(n--){
        int t;
        ll b,x,y;
        scanf("%d%lld%lld%lld",&t,&b,&x,&y);
        vi vx,vy,vres;
        toBase(x,b,vx);
        toBase(y,b,vy);
        calc(vx,vy,b,vres);
        printf("%d %lld\n",t,toTen(b,vres));
    }

    return 0;
}
