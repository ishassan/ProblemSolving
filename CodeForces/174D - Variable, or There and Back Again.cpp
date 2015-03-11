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

const int size = 100002;
int states[size];
vi g[size],revg[size];
bool mark1[size],mark2[size];

void DFS(int idx){
    mark1[idx] = 1;
    if(states[idx]==2) return;
    rep(i,sz(g[idx])){
        if(!mark1[g[idx][i]])
            DFS(g[idx][i]);
    }
}

void DFS2(int idx){
    mark2[idx] = 1;
    if(states[idx]==1) return;
    rep(i,sz(revg[idx])){
        if(!mark2[revg[idx][i]])
            DFS2(revg[idx][i]);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif



    int n,m,a,b;
    scanf("%d%d",&n,&m);
    rep(i,n){
        scanf("%d",states+i);
    }
    rep(i,m){
        scanf("%d%d",&a,&b);
        --a, --b;
        g[a].push_back(b);
        revg[b].push_back(a);
    }

    rep(i,n){
        if(states[i]==1) DFS(i);
        if(states[i]==2) DFS2(i);
    }

    rep(i,n)
            printf(mark1[i] && mark2[i]?"1\n":"0\n");



}





