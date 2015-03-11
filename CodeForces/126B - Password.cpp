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

int F[1000004];
void build(string& str){
    F[0] = 0;
    int l = 0;
    for (int i = 1; i < sz(str); ++i) {
        while(l && str[i] != str[l]) l = F[l-1];
        if(str[i] == str[l]) ++l;
        F[i] = l;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    string str;
    while(cin >> str){
        build(str);
        int res = F[sz(str)-1];
        bool yes=0;
        rep(i,sz(str)-1){
            if(F[i] == res){
                yes=1;
                break;
            }
        }
        if(!yes){
            res = F[res-1];
        }
        if(res == 0) cout << "Just a legend\n";
        else cout << str.substr(0,res) << "\n";
    }

    return 0;
}

