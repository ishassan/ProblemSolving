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

int clr[100005],cnt[100005];
vector<set<int> > vis;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    vis.resize(100005);
    int n,m;
    while(cin >> n >> m){
        vis.clear();
        mem(cnt,0);
        rep(i,n) cin >> clr[i];
        int a,b;
        rep(i,m){
            cin >> a >> b;
            --a,--b;
            a = clr[a], b = clr[b];
            if(a==b) continue;
            if(vis[a].insert(b).second){
                cnt[a]++;
            }

            if(vis[b].insert(a).second){
                cnt[b]++;
            }
        }
        int mx=-1,bst=1<<27;
        rep(i,n){
            if(mx < cnt[clr[i]] || (mx == cnt[clr[i]] && clr[i] < bst)){
                mx = cnt[clr[i]];
                bst = clr[i];
            }
        }
        cout << bst << "\n";

    }

    return 0;
}
