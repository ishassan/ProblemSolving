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

const int MX = 1005;
int n1,n2;
int arr1[MX],arr2[MX];
vector<vi> pos1,pos2;
int memo[MX][MX];
int vis[MX][MX], visID;
int DP(int idx, int lst2){
    if(idx == n1) return 0;
    int& m = memo[idx][lst2];
    if(vis[idx][lst2] == visID) return m;
    vis[idx][lst2] = visID;

    m = DP(idx+1, lst2);
    int num = arr1[idx];
    if(pos2[num].empty()) return m;
    int l2 = (lst2==MX-1)?-1:lst2;
    if(l2 > -1){
        int lstnum = arr2[l2];
        if(num <= lstnum) return m;
    }
    int f = upper_bound(pos2[num].begin(), pos2[num].end(), l2) - pos2[num].begin();
    if(f == sz(pos2[num])) return m;
    m = max(m, DP(idx+1, pos2[num][f])+1);
    return m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    while(tst--){
        pos1.clear(); pos1.resize(100003);
        pos2.clear(); pos2.resize(100003);
        ++visID;
        cin >> n1;
        rep(i,n1) cin>>arr1[i], pos1[arr1[i]].push_back(i);
        cin >> n2;
        rep(i,n2) cin>>arr2[i], pos2[arr2[i]].push_back(i);
        cout << DP(0, MX-1) << "\n";

    }

    return 0;
}

