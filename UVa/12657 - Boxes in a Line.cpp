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

const int SIZE = 100005;
int lf[SIZE], rt[SIZE];
inline void link(int l, int r){
    rt[l] = r;
    lf[r] = l;
}
inline void moveLeft(int x, int y){ // move x left y
    if(x == y || x == lf[y]) return;
    link(lf[x],rt[x]);
    link(lf[y],x);
    link(x,y);

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);
#endif

    int n,m;
    int cs=1;
    while(cin >> n >> m){
        bool isrev=0;
        rt[0]=1, lf[n+1]=n;
        repa(i,1,n,1)
                lf[i] = i-1, rt[i] = i+1;

        int c,x,y;
        while(m--){
            cin >> c;
            if(c == 4) {isrev^=1; continue;}
            cin >> x >> y;
            if(c < 3 && isrev){c = 3-c;}
            if(c == 1){ // x left y
                moveLeft(x,y);
            }
            else if(c == 2){ // move x right y
                // move x right 3 == move x left (rt[3])
                moveLeft(x,rt[y]);
            }
            else if(c == 3){ // swap x,y
                // move x left rt[y], then move y right (lf[x])
                if(y == lf[x]) swap(x,y); // x < y
                int lx = lf[x];
                moveLeft(x,rt[y]);
                moveLeft(y,rt[lx]);
            }
        }
        cout << "Case "<<cs++ << ": ";
        ll sum=0;
        if(!isrev){
            int cur = rt[0];
            int idx=1;
            while(cur <= n){
                if(idx&1) sum += cur;
                idx ^= 1;
                cur = rt[cur];
            }
        }
        else{
            int cur = lf[n+1];
            int idx=1;
            while(cur >= 1){
                if(idx&1) sum += cur;
                idx ^= 1;
                cur = lf[cur];
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
