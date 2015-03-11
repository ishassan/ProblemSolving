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

map<string,string> m1,m2;
void zbt(string& str, map<string,string>& m){
    str.erase(0,1);str.erase(sz(str)-1,1);
    rep(i,sz(str)) if(str[i]==',') str[i]=' ';
    sstr ss(str);
    string s;
    while(ss >> s){
        int idx = s.find(':');
        string k = s.substr(0,idx);
        string v = s.substr(idx+1);
        m[k]=v;
    }
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
        m1.clear();m2.clear();
        string str;
        cin >> str; zbt(str, m1);
        cin >> str; zbt(str,m2);
        vs add,rem,ch;
        repi(it, m1){
            if(m2.count(it->first) == 0){
                rem.push_back(it->first);
            }
            else if(m2[it->first] != it->second){
                ch.push_back(it->first);
            }
        }
        repi(it,m2){
            if(m1.count(it->first) == 0){
                add.push_back(it->first);
            }
        }
        sort(all(add));
        sort(all(rem));
        sort(all(ch));
        if(add.empty() && rem.empty() && ch.empty()){
            cout << "No changes\n\n";
            continue;
        }
        if(sz(add)){
            string sp="+";
            rep(i,sz(add)) cout << sp << add[i], sp=",";
            cout <<"\n";
        }
        if(sz(rem)){
            string sp="-";
            rep(i,sz(rem)) cout << sp << rem[i], sp=",";
            cout <<"\n";
        }
        if(sz(ch)){
            string sp="*";
            rep(i,sz(ch)) cout << sp << ch[i], sp=",";
            cout <<"\n";
        }
        cout <<"\n";

    }

    return 0;
}

