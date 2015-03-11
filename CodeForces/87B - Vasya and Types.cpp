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

map<string,string> m;
string trans(string a){
    int i,j,cnt=0;
    for (i = 0;  i< sz(a) && a[i]=='&'; i++);
    for (j = i;  j< sz(a) && a[j]!='*'; j++);
    string s = m[a.substr(i,j-i)];
    if(s == "" || s == "errtype") return "errtype";
    a=a.replace(i,j-i,s);
    rep(i,sz(a)){
        if(a[i]=='&') --cnt;
        if(a[i]=='*') ++cnt;
    }
    if(cnt < 0) return "errtype";

    s = "void";
    rep(i,cnt) s +="*";
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
//      freopen("out.txt","wt",stdout);
#endif

    m["void"] = "void";
    m["errtype"] = "errtype";
    int n;
    cin >> n;
    string w,a,b;
    rep(i,n){
        cin >> w;
        if(w == "typeof"){
            cin >> a;
            cout << trans(a) <<"\n";
        }
        else{
            cin >> a >> b;
            m[b] = trans(a);
        }
    }
    return 0;
}

