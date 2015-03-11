#include <bits/stdc++.h>

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
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    string a,b,str1,str2;
    cin >> a >> b;
    int s1=0,s2=0;
    bool f=0;
    rep(i,sz(a)){
        if(a[i]=='|'){f=1;continue;}
        if(f) s2++,str2+=a[i];
        else s1++,str1+=a[i];
    }
    bool sw=0;
    if(s1 > s2)swap(str1,str2),swap(s1,s2),sw=1;
    int add = s2-s1, n = sz(b);
    n-=add;
    if(n < 0 || (n&1)){cout << "Impossible";return 0;}
    int i;
    for (i = 0; i < add+(n/2); ++i) {
        str1+=b[i];
    }
    for (; i < sz(b); ++i) {
        str2+=b[i];
    }
    if(sw) swap(str1,str2);
    a = str1 + "|" + str2;
    cout << a;
    return 0;
}

