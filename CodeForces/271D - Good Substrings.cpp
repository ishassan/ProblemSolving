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
struct hashf{
    int operator()(const pair<int,int>& p)const{
        return p.first*31+p.second;
    }
};

const int mod1 = 1e9+7,mod2=10000019;
pii hashes[1502];
int cumbad[1502];
ll pwr[1502][2];
bool bad[26];
const int base = 26;
string str;
unordered_set<pii,hashf> vis;
void build(){
    pair<ll,ll> h;
    rep(i,sz(str)){
        h.first *= base; h.first%=mod1;
        h.first += str[i]-'a'+1; h.first%=mod1;
        h.second *= base; h.second%=mod2;
        h.second += str[i]-'a'+1; h.second%=mod2;
        hashes[i] = h;
        cumbad[i] = bad[str[i]-'a'] + (i==0?0:cumbad[i-1]);
    }
}
pii getsubstr(int st, int en){
    if(st == 0) return hashes[en];
    int len = en-st+1;
    pair<ll,ll> h;
    h.first =(hashes[st-1].first*pwr[len][0])%mod1;
    h.first = (hashes[en].first-h.first+mod1)%mod1;
    h.second =(hashes[st-1].second*pwr[len][1])%mod2;
    h.second = (hashes[en].second-h.second+mod2)%mod2;
    return h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    pwr[0][0] =pwr[0][1] = 1;
    repa(i,1,1501,1) {
        pwr[i][0] = (pwr[i-1][0]*base)%mod1;
        pwr[i][1] = (pwr[i-1][1]*base)%mod2;
    }

    while(cin >> str){
        vis.clear();
        string sbad; int k;
        cin >> sbad >> k;
        rep(i,sz(sbad)) bad[i] = (sbad[i]=='0');
        build();
        int res=0;
        rep(i,sz(str)){
            repa(j,i,sz(str)-1,1){
                if(cumbad[j] - cumbad[i] + bad[str[i]-'a'] > k) break;
                pii sub = getsubstr(i,j);
                if(vis.insert(sub).second) ++res;
            }
        }
        cout << res << "\n";
    }


    return 0;
}

