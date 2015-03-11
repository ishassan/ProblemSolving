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

int n,l;
int arr[102][2];

ll memo[105][2][3002];
int mod = 1000000007;
ll DP(int lst, int ldim, int rem){
    if(rem == 0)
        return 1;
    if(rem < 0) return 0;
    ll& m = memo[lst][ldim][rem];
    if(m != -1) return m;
    int eq = arr[lst][!ldim];
    m=0;
    rep(i,n){
        if(i == lst) continue;
        if(eq == arr[i][0]){
            m += DP(i,0,rem-eq);
            if(m > mod)
                m %= mod;
        }
        else if(eq == arr[i][1]){
            m += DP(i,1,rem-eq);
            if(m > mod)
                m %= mod;
        }
    }
    return m;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    scanf("%d%d",&n,&l);
    rep(i,n)scanf("%d%d",&arr[i][0],&arr[i][1]);
    mem(memo,-1);
    ll m=0;
    rep(i,n){
        m += DP(i,0,l-arr[i][0]);
        if(m > mod)
            m %= mod;
        if(arr[i][0] == arr[i][1]) continue;
        m += DP(i,1,l-arr[i][1]);
        if(m > mod)
            m %= mod;
    }
    cout << m;
}





