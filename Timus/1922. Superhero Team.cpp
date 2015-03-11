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

pii arr[2000];
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
        cin >> arr[i].first, arr[i].second=i+1;

    sort(arr,arr+n);
    vector<vi> res;
    vi v;
    bool t=0;
    rep(i,n){
        if(arr[i].first<=i+1) {
            t=1;
        }
        else{
            if(t) res.push_back(v);
            t=0;
        }
        v.push_back(arr[i].second);
    }
    if(t)res.push_back(v);
    cout << sz(res) << "\n";
    rep(i,sz(res)){
        cout << sz(res[i]);
        rep(j,sz(res[i])){
            cout << " " << res[i][j];
        }
        cout << "\n";
    }


    return 0;
}

