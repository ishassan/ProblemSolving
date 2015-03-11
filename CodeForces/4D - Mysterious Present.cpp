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

bool cmp(pii a, pii b){
    return b.first > a.first && b.second > a.second;
}
const int SIZE = 5003;
int memo[SIZE];
vector<pair<pii,int> > v;
int DP(int lst){
    int& m = memo[lst];
    if(m != -1) return m;
    m = 0;
    rep(i,sz(v)){
        if(lst == SIZE-1 || cmp(v[lst].first, v[i].first))
        m = max(m, DP(i)+1);
    }
    return m;
}

void build(int lst){
    int m = DP(lst);
    rep(i,sz(v)){
        if(lst == SIZE-1 || cmp(v[lst].first, v[i].first)){
            if(m == DP(i)+1){
                cout << v[i].second << " ";
                build(i);
                return;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n,w,h;
    while(cin >> n >> w >> h){
        v.clear();
        v.reserve(n+2);
        vi res;
        int a,b;
        rep(i,n) {
            cin >> a >> b;
            if(cmp(mp(w,h) , mp(a,b))){
                v.push_back(mp(mp(a,b),i+1));
            }
        }
        sort(all(v));
        mem(memo,-1);
        int l = DP(SIZE-1);
        cout << l << "\n";
        build(SIZE-1);
        cout << "\n";
    }

    return 0;
}
