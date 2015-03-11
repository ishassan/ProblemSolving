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

map<string,string> m;
map<string,vs> mv;
vs l;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n;
    string str;
    getline(cin,str);
    sstr z(str);
    z >> n;
    rep(i,n){
        getline(cin,str);
        sstr ss(str);
        string lang,s;
        ss >> lang;
        vs& v = mv[lang];
        l.push_back(lang);
        while(ss >> s){
            rep(i,sz(s)) s[i] = tolower(s[i]);
            v.push_back(s);
            m[s]=lang;
        }
    }
    getline(cin,str);
    while(getline(cin,str)){
        rep(i,sz(str)) str[i] = tolower(str[i]);
        string res;
        rep(i,sz(l)){
            vs& v = mv[l[i]];
            rep(j,sz(v)){
                int idx = str.find(v[j],0);
                if(idx == str.npos) continue;
                if(idx == 0 || !isalpha(str[idx-1])){
                    if(idx + sz(v[j]) == sz(str) || !isalpha(str[idx+sz(v[j])])){
                        res = m[v[j]];
                        goto end;
                    }
                }
            }
        }
        end:;
        cout << res << "\n";
    }


    return 0;
}

