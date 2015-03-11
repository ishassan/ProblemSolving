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

int sumd(ll x){
    int sum=0;
    while(x){
        sum += x%10;
        x/=10;
    }
    return sum;
}

ll sqrt(ll x){
    ll st=1, en = x;
    rep(i,70){
        ll mid = (st+en)/2;
        if( x%mid == 0 && mid == x/mid) return mid;
        if(mid > x/mid) en = mid;
        else st = mid+1;
    }
    return -1;
}
ll fok(ll b, ll c){
    if(c > b*b) return -1;
    if(4*c > b*b) return -1;
    ll sqr = sqrt(b*b - 4*c);
    if(sqr == -1) return -1;
    double r1 = (-b+sqr)/2.0;
    double r2 = (-b-sqr)/2.0;
    if(r1 > r2) swap(r1,r2);
    ll lr1 = round(r1);
    ll lr2 = round(r2);
    if(lr1 > 0 && fabs(r1 - lr1)<1e-7 && b == sumd(lr1))
        return lr1;
    if(lr2 > 0 && fabs(r2 - lr2)<1e-7 && b == sumd(lr2) )
        return lr2;
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    ll n;
    cin >> n;
    ll mn = 1LL<<58;
    repa(i,1,165,1){
        ll res = fok(i,-n);
        if(res != -1)
          mn = min(mn, res);  
    }
    if(mn >= 1LL<<58)
        mn = -1;
    cout << mn;
    return 0;
}