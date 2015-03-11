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
int memo[1002][12][12];
vi v;
bool DP(int idx, int diff, int lst){
    if(idx == n) return 1;
    int& m = memo[idx][diff][lst];
    if(m != -1) return m;
    m = 0;
    rep(i,sz(v)){
        if(v[i]==lst || v[i] <= diff) continue;
        m |= DP(idx+1,v[i]-diff,v[i]);
    }
    return m;
}
void build(int idx, int diff, int lst){
    if(idx == n) return ;
    
    rep(i,sz(v)){
        if(v[i]==lst || v[i] <= diff) continue;
        if(DP(idx+1,v[i]-diff,v[i])){
            cout << v[i] << " ";
            build(idx+1,v[i]-diff,v[i]);
            break;
        }
    }
}
int main()
{
    
    #ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
    #endif
    
    mem(memo,-1);
    repa(i,1,10,1){scanf(" %c",&n); if(n=='1') v.push_back(i);}
    scanf("%d",&n);
    if(!DP(0,0,0)){cout << "NO"; return 0;}
    cout << "YES\n";
    build(0,0,0);
    return 0;
}