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

struct ant{
    int x,idx,dir;
    bool operator<(const ant& a)const{
        if(x < a.x) return 1;
        if(x > a.x) return 0;
        return idx < a.idx;
    }
};
vector<ant> v;
int n,l;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n >> l && (n || l)){
        v.clear(); v.resize(n);
        char a; int x;
        rep(i,n){
            cin >> a >> x;
            v[i] = {x,i+1,a=='R'?1:-1};
        }
        int tm=0,res=-1;
        while( (n=v.size()) ){
            sort(all(v));

            for (int i = n-1; i >= 0; --i) {
                if(i && v[i].x + v[i].dir <= v[i-1].x+v[i-1].dir)
                     if(((v[i].x - v[i-1].x)&1) == 0)
                        swap(v[i].idx, v[i-1].idx);
                v[i].x += v[i].dir;
                if(v[i].x <= 0 || v[i].x >= l){
                    res = v[i].idx;
                    v.erase(v.begin()+i);
                }
            }
            ++tm;
        }
        cout << tm << " " << res << "\n";

    }

    return 0;
}

