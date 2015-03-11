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

pii arr[3003];
bool vis[3003][3003];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int n;
    scanf("%d",&n);
    rep(i,n){
        scanf("%d%d",&arr[i].first, &arr[i].second);
        vis[arr[i].first+1000][arr[i].second+1000]=1;
    }
    int cnt=0;
    rep(i,n)
            reps(j,i+1,n){
        int mxx = max(arr[i].first,arr[j].first), mnx = min(arr[i].first,arr[j].first);
        int mxy = max(arr[i].second,arr[j].second), mny = min(arr[i].second,arr[j].second);
        if((mxx-mnx)%2 || (mxy-mny)%2) continue;
        int xx = mxx - ((mxx-mnx)/2) , yy = mxy-((mxy-mny)/2);
        if(vis[xx+1000][yy+1000])
            ++cnt;
    }
    printf("%d\n",cnt);

}





