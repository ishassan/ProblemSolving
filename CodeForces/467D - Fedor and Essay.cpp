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

unordered_map<string,pii> mapp;
inline int cntr(string& str){
    int cnt=0;
    rep(i,sz(str)) cnt += (str[i]=='r');
    return cnt;
}
void tolow(string& str){
    rep(i,sz(str)) str[i] = tolower(str[i]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n,m;
    while(cin >> n){
        mapp.clear();
        string x,y;
        vs v;
        rep(i,n) {
            cin >> x;
            tolow(x);
            v.push_back(x);
            mapp[x] = mp(cntr(x), sz(x));
        }
        cin >> m;
        vector<pair<string,string> > vecs;
        rep(i,m){
            cin >> x >> y;
            tolow(x); tolow(y);
            if(!mapp.count(x)){
                mapp[x] = mp(cntr(x), sz(x));
            }
            if(!mapp.count(y)){
                mapp[y] = mp(cntr(y), sz(y));
            }
            vecs.push_back(mp(x,y));
        }
        bool yes=1;
        while(yes){
            yes=0;
            rep(i,m){
                x = vecs[i].first;
                y = vecs[i].second;
                pii p = mapp[x];
                pii p2 = mapp[y];
                if(p2.first < p.first || (p2.first == p.first && p2.second < p.second)){
                    mapp[x] = mapp[y];
                    yes=1;
                }
            }
        }
        ll bstr=0,bstlen=0;
        rep(i,sz(v)){
            pii p = mapp[v[i]];
            bstr += p.first;
            bstlen += p.second;
        }
        cout << bstr << " " << bstlen << "\n";

    }

    return 0;
}
