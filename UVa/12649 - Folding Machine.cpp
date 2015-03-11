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



vi v1,v2;
int n,m;
bool equal(vi& v1, vi& v2, int len){
    bool s=1,r=1;
    rep(i,len){
        if(v1[i] != v2[i]) s=0;
        if(v1[i] != v2[len-i-1]) r=0;
        if(!s && !r) return 0;
    }
    return 1;
}
bool DFS(vi& v, int len){
    if(len == m){
        return equal(v, v2, len);
    }

    vi tmp(len);
    repa(i,1,len-1,1){
        int idx1 = i-1, idx2 = i;
        int nwlen=0;
        while(idx1 >=0 || idx2 < len){
            if(idx1 < 0){
                tmp[nwlen++] = v[idx2++];
                continue;
            }
            if(idx2 >= len){
                tmp[nwlen++] = v[idx1--];
                continue;
            }
            tmp[nwlen++] = v[idx2++] + v[idx1--];
        }
        if(DFS(tmp, nwlen)) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n){
        v1.clear(); v2.clear();
        v1.resize(n);
        rep(i,n) cin >> v1[i];
        cin >> m;
        v2.resize(m);
        rep(i,m) cin >> v2[i];
        if(DFS(v1,n)) cout << "S\n";
        else cout << "N\n";
    }
    return 0;
}
