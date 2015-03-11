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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    string str;
    cin >> str;
    ll a=0,b=0;
    int idx = indexof(str,'^');
    rep(i,idx){
        if(isdigit(str[i]))
            a += (idx-i)*(str[i]-'0');
    }
    repa(i,idx+1,sz(str)-1,1){
        if(isdigit(str[i]))
            b += (i-idx)*(str[i]-'0');
    }
    printf("%s",a==b?"balance":(a>b)?"left":"right");
}
