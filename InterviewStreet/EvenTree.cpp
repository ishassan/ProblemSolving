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

vector<vi> tree;
int res=0;

int getchild(int idx, int prev){
    int sum=0;
    rep(i,sz(tree[idx])){
        int nxt = tree[idx][i];
        if(nxt == prev) continue;
        int tmp = getchild(nxt,idx) + 1;
        if(tmp % 2 ==0){
            ++res;
            tree[idx].erase(tree[idx].begin()+i);
            --i;
        }
        else
            sum += tmp;

    }
    return sum;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int n,m,a,b;
    scanf("%d%d",&n,&m);
    tree = vector<vi>(n);
    rep(i,m){
        scanf("%d%d",&a,&b);
        --a,--b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    getchild(0,-1);
    printf("%d\n",res);
}

