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

pii arr[1004];

string B = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int I(char c) { return B.find(c);       }

// add "1234" + "56546" = "57780"
string add(string a, string b, int base) {
    int mx = max(sz(a), sz(b));

    int C[1010] = {0};

    while( sz(a) != mx)     a = "0" + a;
    while( sz(b) != mx)     b = "0" + b;

    reverse( all(a) );
    reverse( all(b) );

    for (int i = 0; i < mx; ++i) {
        int t = C[i] + I(a[i]) + I(b[i]);
        C[i]    = t % base, C[i+1] += t / base;
    }

    int i = C[mx]=='1'?mx:mx-1;
//    while(i > 0 && C[i] == 0)       i --;

    string ret = "";
    for (int j = i; j >= 0; --j) ret += B[ C[j] ];

    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n;
    cin >> n;
    rep(i,n)
            cin >> arr[i].first, arr[i].second = i;
    sort(arr,arr+n);
    bool yes=1;
    vector<pair<int,string > > res;
    string cur = "-1";
    rep(i,n){
        if(cur == "-1") cur = string(arr[i].first, '0');
        else{
            cur = add(cur,"1",2);
            while(sz(cur) < arr[i].first) cur += "0";
            if(cur == string(sz(cur),'1') && i+1 < n){
                yes=0;
                break;
            }
        }
        res.push_back(mp(arr[i].second, cur));
    }

    if(!yes){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    sort(all(res));
    rep(i,sz(res)) cout << res[i].second << "\n";
    return 0;
}
