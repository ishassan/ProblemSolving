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

string str,res,bld;
int h;
bool dfs(int idx, bool isgreat, int c4, int c7){
    if(idx == sz(str)) return c4==c7;
    if(c4 > h || c7 > h) return 0;
    if(isgreat){
        bld += string(h-c4,'4');
        bld += string(h-c7,'7');
        res = bld;
        return 1;
    }
    if(str[idx] <= '4'){
        bld += "4";
        if(dfs(idx+1,str[idx]<'4',c4+1,c7)){
            res = bld;
            return 1;
        }
        bld[sz(bld)-1] = '7';
        if(dfs(idx+1,1,c4,c7+1)){
            res = bld;
            return 1;
        }
        bld.pop_back();
    }
    else if(str[idx] <= '7'){
        bld += "7";
        if(dfs(idx+1,str[idx]<'7',c4,c7+1)){
            res = bld;
            return 1;
        }
        bld.pop_back();
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

    cin >> str;
    if(sz(str)&1){
        int n = (sz(str)+1)/2;
        rep(i,n) cout <<4;
        rep(i,n) cout <<7;
        return 0;
    }
    h = sz(str)/2;
    if(dfs(0,0,0,0)){
        cout << res;
        return 0;
    }
    h++;
    cout << string(h,'4') << string(h,'7');

    return 0;
}
