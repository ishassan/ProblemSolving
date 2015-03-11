#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
#define itr(A,B) typeof(B) A = B
typedef long long ll;
using namespace std;

string str;

char merge(char a, char b){
    string tmp = string(1,a)+b;
    sort(all(tmp));
    if(tmp =="ab") return 'c';
    if(tmp =="ac") return 'b';
    if(tmp =="bc") return 'a';
    return 0;
}

bool workRight(int& st, int& en){
    if(en + 1 == sz(str)) return 0;
    if(st == en){
        while(en+1<sz(str) && str[en] != str[en+1]){
            char c = merge(str[en],str[en+1]);
            if(c == 0) cout << 1/(1-1);
            str.erase(en+1,1);
            str[en]=c;
        }
        return 1;
    }
    while(en+1 < sz(str) && st < en){
        char c = merge(str[en], str[en+1]);
        if(c == 0) cout << 1/(1-1);
        str.erase(en+1,1);
        str[en]=c;
        --en;
    }
    return 1;
}

bool workLeft(int& st, int& en){
    if(st == 0 || st==en) return 0;
    while(st > 0 && st < en){
        char c = merge(str[st], str[st-1]);
        if(c == 0) cout << 1/(1-1);
        str[st]=c;
        str.erase(st-1,1);
        --en;
    }
    return 1;
}

pii getLongest(){
    int st=0,en=0,len=1;
    int mxst=0,mxen=0,mxlen=1;
    char lst = str[0];
    reps(i,1,sz(str)){
        if(str[i]==lst){
            ++len, ++en;
            if(len > mxlen){
                mxlen = len;
                mxst = st, mxen = en;
            }
        }
        else{
            len = 1, st=en=i;
            lst = str[i];
        }
    }
    return mp(mxst,mxen);
}

int main(){
//#ifndef ONLINE_JUDGE
//    freopen("in","rt",stdin);
//    freopen("out","wt",stdout);
//#endif

    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    while(n--){
        cin >> str;
        bool yes=1;
        while(yes){
            yes=0;
            pii p = getLongest();
            yes |= workRight(p.first, p.second);
            yes |= workLeft(p.first, p.second);
        }
        cout << sz(str)<<endl;
    }
    
}





