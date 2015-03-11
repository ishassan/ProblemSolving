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

char str[1000];
struct state{
    int a,b,c;
};

vector<state> v[12];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    rep(i,n){
        scanf("%s",str);
        rep(j,m){
            state s;
            scanf("%d%d%d",&s.a,&s.b,&s.c);
            v[i].push_back(s);
        }
    }

    int mx=0;
    rep(i,n){
        rep(j,n){
            int val=0;
            if(i==j) continue;
            vector<pii> pro;
            rep(kk,sz(v[i])){
                if(v[j][kk].b <= v[i][kk].a) continue;
                pro.push_back(mp(v[j][kk].b - v[i][kk].a, v[i][kk].c));
            }
            int lim = k;
            sort(pro.rbegin(),pro.rend());
            rep(kk,sz(pro)){
                if(pro[kk].second <= lim){
                    lim -= pro[kk].second;
                    val += pro[kk].first*pro[kk].second;
                }
                else{
                     val += pro[kk].first*lim;
                     break;
                }
            }
            mx = max(mx,val);
        }
    }
    printf("%d\n",mx);

}





