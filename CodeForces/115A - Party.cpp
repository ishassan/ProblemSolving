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

set<int> levels;
int sup[2002];
vi under[2002];
void dfs(int idx, int lvl){
    levels.insert(lvl);
    if(under[idx].size()==0) return;
    rep(i,sz(under[idx]))
        dfs(under[idx][i],lvl+1);
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    int n,x;
    cin >> n;
    repa(i,1, n,1) {
        cin >> x;
        sup[i]=x;
        if(x>-1)
            under[x].push_back(i);
    }
    repa(i,1,n,1)
        if(sup[i]==-1) dfs(i,1);
        printf("%d\n",levels.size());
    return 0;
}
