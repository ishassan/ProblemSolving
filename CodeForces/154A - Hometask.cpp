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


string v[300];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    int k,res=0;
    string str,s;
    cin >> str >> k;
    rep(i,k){
        cin >> s;
        v[s[0]] = v[s[1]] = s;
    }
    rep(i,sz(str)){
        if(v[str[i]] == "") continue;
        s = v[str[i]];
        int cnt0=0,cnt1=0;
        while(i < sz(str) && (str[i]==s[0] || str[i]==s[1])){
            cnt0 +=str[i]==s[0];
            cnt1 +=str[i]==s[1];
            ++i;
        }
        res += min(cnt0,cnt1);
        --i;

    }
    cout << res;
    return 0;
}
