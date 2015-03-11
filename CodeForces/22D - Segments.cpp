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

vector<pair<int, pii> > arr; //pos, isend
vector<pii> org;
bool vis[1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    int n,a,b;
    cin >> n;
    rep(i,n) {
        cin >> a >> b;
        if(a > b) swap(a,b);
        arr.push_back(mp(a,mp(0,i)));
        arr.push_back(mp(b,mp(1,i)));
        org.push_back(mp(a,b));
    }
    sort(all(arr));
    bool start=0;
    vi res;
    res.push_back(-1<<27);
    rep(i,sz(arr)){
        if(arr[i].second.first == 0){
            start = 1;
        }
        else if (start){
            int idx = arr[i].second.second;
            if(org[idx].first > res.back()){
                res.push_back(org[idx].second);
                start = 0;
            }

        }
    }

    cout << sz(res)-1 << "\n";
    repa(i,1,sz(res)-1,1) cout << res[i] << " ";
    return 0;
}
