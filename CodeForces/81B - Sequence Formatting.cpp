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

string str;
int cntsp(int idx, int step){
    int cnt=0;
    for(int i = idx; i >= 0 && i < sz(str); i += step){
        if(str[i] == ' ') ++cnt;
        else return cnt;
    }
    return cnt;
}
int checkDigit(int& idx){
    while(isdigit(str[idx])) ++idx;
    int st = idx,en=idx;
    repa(i,st,sz(str)-1,1){
        if(str[i] != ' ') break;
        ++en;
    }
    if(en < sz(str) && isdigit(str[en]) && en>st){
        str = str.erase(st,en-st-1);
        return idx;
    }
    else
        return idx-1;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(getline(cin,str)){
        rep(i,sz(str)){
            if(str[i]==','){
                int sp = cntsp(i+1,1);
                if(i+1 < sz(str)){
                    str = str.erase(i+1,sp);
                    str = str.insert(i+1," ");
                    ++i;
                    continue;
                }
            }
            else if(str[i] == '.'){
                int sp = cntsp(i-1,-1);
                if(i && sp != 1){
                    str = str.erase(i-sp, sp);
                    str = str.insert(i," ");
                    ++i;
                }
                i += 2;
            }
            else if(isdigit(str[i])){
                int ni = checkDigit(i);
                i = ni;
            }
            else if(str[i] == ' ') {
                str = str.erase(i,1);
                --i;
            }
        }
        cout << str << "\n";
    }

    return 0;
}

