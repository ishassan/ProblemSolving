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

int n,s,p;
int arr[102];
int memo[102][102];
int DP(int idx, int sur){
    if(idx == n && sur == 0)
        return 0;
    if(idx == n) return -1<<27;

    int& m = memo[idx][sur];
    if(m != -1) return m;
    m = 0;
    int t1 = arr[idx]/3;
    int t2=t1,t3=t1;
    if(arr[idx]%3==1) ++t3;
    if(arr[idx]%3==2) ++t3,++t2;
    if(t3<=10){
        m = DP(idx+1, sur)+(t3 >= p);
    }
    if(arr[idx]%3==1)
        ++t2,--t1;
    else
        ++t3,--t2;
    if(sur > 0 && t3<=10 && t2 >= 0)
        m = max(m, DP(idx+1, sur-1) + (t3 >= p));
    return m;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int tst;
    scanf("%d",&tst);
    repe(t,1,tst){
        scanf("%d%d%d",&n,&s,&p);
        rep(i,n) scanf("%d",arr+i);
        mem(memo,-1);
        printf("Case #%d: %d\n",t,DP(0,s));
    }


}





