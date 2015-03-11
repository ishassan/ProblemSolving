#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int n,m;
int a1[100004], a2[100004];
ll eval(ll num){
    ll sum = 0;
    rep(i,n) if(a1[i] < num) sum += num-a1[i];
    rep(i,m) if(a2[i] > num) sum += a2[i]-num;
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    cin >> n >> m;
    rep(i,n) cin >> a1[i];
    rep(i,m) cin >> a2[i];
    sort(a1, a1+n);
    sort(a2, a2+m);

  // ternary
//    int st=0;
//    double siz=1e9+10;
//    for(;siz>1e-9;siz=(siz*2.0)/3){
//        int m1 = round(st+siz/3.0);
//        int m2 = round(st+(2.0*siz)/3.0);
//        if(eval(m1) >= eval(m2))
//            st = m1;
//    }
//    cout << eval(st);

    //ternary using binary
    ll st=0, en = 1e9+10;
    while(st < en){
        ll mid = (st+en)>>1;
        ll e1 = eval(mid), e2 = eval(mid+1);
        if(eval(mid) > eval(mid+1))
            st = mid+1;
        else
            en = mid;
    }
    cout << eval(st);
    return 0;
}
