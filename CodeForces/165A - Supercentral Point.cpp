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


int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int n;
    scanf("%d",&n);
    vector<pii> v(n);
    rep(i,n)
            scanf("%d %d",&v[i].first,&v[i].second);

    int res=0;
    rep(i,n){
        bool up=0,down=0,left=0,right=0;
        rep(j,n){
            if(i == j) continue;
            if(v[j].first > v[i].first && v[j].second == v[i].second) right =1;
            if(v[j].first < v[i].first&& v[j].second == v[i].second) left =1;
            if(v[j].second < v[i].second&& v[j].first == v[i].first) down=1;
            if(v[j].second > v[i].second&& v[j].first == v[i].first) up=1;
        }
        if(up && down && left && right)
            ++ res;
    }
    printf("%d\n",res);
}





