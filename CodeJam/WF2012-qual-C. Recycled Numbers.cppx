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

int a,b,cnt;
ll powr10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
set<pii> res;
void calc(int num){
    res.clear();
    int len=0,n=num;
    while(n) n/=10,++len;
    for (int i = 1; i< len; i++) {
        ll p1 = powr10[i];
        ll p2 = powr10[len-i];
        ll r = num%p1, l = num/p1;
        r = r*p2+l;
        if(r >= a && r<= b && r>num && res.insert(mp(num,r)).second)
            ++cnt;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int tst;
    scanf("%d",&tst);
    repe(t,1,tst){
        scanf("%d%d",&a,&b);
        cnt =0;
        repe(i,max(12,a),b)
            calc(i);
        printf("Case #%d: %d\n",t,cnt);
    }


}





