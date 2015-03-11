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

char g[200][200];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int h,w;
    scanf("%d%d",&h,&w);
    vector<pii> v;
    rep(i,h){
            scanf("%s",g[i]);
            rep(j,w){
                if(g[i][j]=='*')
                    v.push_back(mp(i,j));
            }
    }
    int r,c;
    if(v[0].first == v[1].first)
        r = v[2].first;
    else if(v[0].first == v[2].first)
        r = v[1].first;
    else
        r = v[0].first;

    if(v[0].second == v[1].second)
        c = v[2].second;
    else if(v[0].second== v[2].second)
        c = v[1].second;
    else
        c = v[0].second;

    printf("%d %d",r+1,c+1);



}





