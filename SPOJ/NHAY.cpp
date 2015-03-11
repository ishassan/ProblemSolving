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

vector<int> F;

void computePrefix(const string &pattern) {
    F.resize(pattern.size());
    F[0] = 0;
    int l = 0;
    for (int i = 1; pattern[i]; i++) {
        while (l && pattern[i] != pattern[l])
            l = F[l - 1];
        if (pattern[i] == pattern[l])
            l++;
        F[i] = l;
    }
}

void KMP(const string &str, const string &pattern, vector<int>&ans) {
    ans.clear(); F.clear();
    computePrefix(pattern);
    int l = 0;
    for (int i = 0; str[i]; i++) {
        while (l && str[i] != pattern[l])
            l = F[l - 1];
        if (str[i] == pattern[l])
            l++;
        if (l == (int)pattern.size()) {
            ans.push_back(i - l + 1);
            l = F[l - 1]; // l = 0 => no overlap
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n;
    string pat,str,sep;
    while(cin >> n >> pat >> str){
        vi ans;
        KMP(str,pat,ans);
        cout << sep;
        sep = "\n";
        rep(i,sz(ans)) cout << ans[i] << "\n";
    }
    return 0;
}
