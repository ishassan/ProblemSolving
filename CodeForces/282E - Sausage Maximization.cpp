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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

ll n,arr[100003],pre[100003],suf[100003];
int bitidx;
bool cmp(ll a, ll b){
    return ((a>>bitidx)&1) < ((b>>bitidx)&1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);
#endif

    cin >> n;
    pre[0]=0;
    rep(i,n) {
        cin >> arr[i];
        pre[i+1] = pre[i]^arr[i];
    }
    suf[0] = 0;
    rep(i,n) suf[i+1] = suf[i]^arr[n-i-1];

    sort(suf,suf+n+1);
    ll mx = 0;
    repa(k,0,n,1){
        int st=0,en=n;
        repd(i,40,0,1){
            int bit = (pre[k]>>i)&1;
            bitidx = i;
            int pos = lower_bound(suf+st, suf+en+1, (1LL<<i),cmp)-suf;
            if(pos > en) continue;
            if(!bit)
                st = pos;
            else
                en = pos-1;
        }
        mx = max(mx, pre[k]^suf[st]);
    }
    cout << mx;
    return 0;
}
