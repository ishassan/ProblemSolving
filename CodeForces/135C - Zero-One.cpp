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

int freq[128];

string simulate(string& str){
    queue<int> q[2];
    rep(i,sz(str)) q[str[i]-'0'].push(i);
    bool cur=1;
    while(q[0].size()+q[1].size() >2){
        q[cur].pop();
        cur =!cur;
    }

    if(q[0].front() < q[1].front()) return "01";
    return "10";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    string str;
    cin >> str;
    rep(i,sz(str)) freq[str[i]]++;
    set<string> ans;
    repa(extraZeros,0, freq['?'],1){
        int zeros = freq['0'] + extraZeros;
        int ones= freq['1'] + freq['?'] - extraZeros;
        if(zeros - ones > 0) {ans.insert("00"); continue;}
        if(ones - zeros > 1) {ans.insert("11"); continue;}
        int cnt=0;
        string tmp = str;
        rep(i,sz(tmp))
                if(tmp[i]=='?'){
            if(cnt++ < extraZeros)
                tmp[i]='0';
            else
                tmp[i]='1';
        }
        ans.insert(simulate(tmp));
        tmp = str;
        cnt=0;
        rep(i,sz(tmp))
                if(tmp[i]=='?'){
            if(cnt++ < freq['?']-extraZeros)
                tmp[i]='1';
            else
                tmp[i]='0';
        }
        ans.insert(simulate(tmp));

    }
    repi(it, ans) cout <<*it <<endl;
    return 0;
}
