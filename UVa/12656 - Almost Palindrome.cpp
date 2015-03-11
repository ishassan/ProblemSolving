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

int k;
string str;
inline int nxtpos(int idx){
    for (int i = idx+1; i < sz(str); ++i) {
        if(isalpha(str[i])) return i;
    }
    return -1;
}
inline int prvpos(int idx){
    for (int i = idx-1; i >= 0; --i) {
        if(isalpha(str[i])) return i;
    }
    return -1;
}

pii getMax(bool odd){
    int bpos,mx=0;
    rep(i,sz(str)){
        if(!isalpha(str[i]))continue;
        int st=i,en=odd?i:nxtpos(i);
        int cnt = 0;
        while(st > -1 && en > -1){
            cnt += (tolower(str[st]) != tolower(str[en]));
            if(cnt > k) break;
            if(mx < en-st+1){
                mx = en-st+1;
                bpos = st;
            }
            st = prvpos(st), en = nxtpos(en);
        }
    }
    return mp(mx,bpos);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int cs=1;
    while(cin >> k){
        getline(cin,str);
        getline(cin,str);
        pii res0 = getMax(0),res1=getMax(1),mx;
        if(res0.first > res1.first || (res0.first == res1.first && res0.second < res1.second) )
            mx = res0;
        else mx=res1;
        cout << "Case " << cs++ << ": " << mx.first << " " << mx.second+1 << "\n";
    }

    return 0;
}

