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
typedef long long ll;
using namespace std;

bool cmp(pair<pii,int> a, pair<pii,int> b){
    if(a.first.first < b.first.first) return 1;
    if(a.first.first > b.first.first) return 0;
    if(a.first.second > b.first.second) return 1;
    return 0;
}

bool eq(double a, double b){
    return fabs(a-b)<1e-9;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int n,a,d,v,t;
    scanf("%d%d%d",&n,&a,&d);
    double r,mx =0;
    vector<pair<pii,int> > vc;
    vector<double> res(n);

    rep(i,n){
        scanf("%d%d",&t,&v);
        vc.push_back(mp(mp(t,v),i));
    }
    sort(all(vc),cmp);
    rep(i,n){
        t = vc[i].first.first;
        v = vc[i].first.second;
        int idx = vc[i].second;
        double finalt = (double)v/a;
        double calcd = v*finalt/2.0;
        r = t;
        if(d < calcd || eq(d,calcd)){
            r += sqrt(d/(0.5*a));
        }
        else{
            double rem = d-calcd;
             r += finalt + rem/v;
        }

        r = max(r, mx);
        res[idx] = r;
        mx = max(r,mx);
    }
    rep(i,n)
    {
        printf("%.10lf\n",res[i]);
    }

}





