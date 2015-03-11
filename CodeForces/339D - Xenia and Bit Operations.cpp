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

int arr[18], segtree[1<<18];
int n,m;
bool orparity;
int idx, val;
int update(int ni=0, int st=0, int en=(1<<n)-1, int lvl=0){
    if(st > idx || en < idx) return segtree[ni];
    if(st == en) {
        segtree[ni] = val;
        return val;
    }
    int mid = st + ((en-st)>>1);
    update(ni*2+1, st,mid,lvl+1);
    update(ni*2+2, mid+1,en, lvl+1);
    if((lvl&1) == orparity)
        segtree[ni] = segtree[ni*2+1] | segtree[ni*2+2];
    else
        segtree[ni] = segtree[ni*2+1] ^ segtree[ni*2+2];

    return segtree[ni];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif


    cin >> n >> m;
    orparity = (n-1)&1;
    rep(i,1<<n) {
        cin >> val;
        idx = i;
        update();
    }
    while(m--){
        cin >> idx >> val, --idx;
        cout << update() << "\n";
    }
    return 0;
}
