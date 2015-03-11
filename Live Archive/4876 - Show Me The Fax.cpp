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

int eval(char c){
    if(isdigit(c)) return c-'0';
    return c-'A'+10;
}

string tobinary(int n){
    string res;
    while(n){
        res += (n%2) + '0';
        n /= 2;
    }
    reverse(all(res));
    while(sz(res) < 4) res = "0"+res;
    return res;
}

int todecimal(string bi){
   int pw = 1;
   int res=0;
   for (int i = sz(bi)-1; i >= 0; --i) {
       res += pw*(bi[i]-'0');
       pw *= 2;
   }
   return res;
}

string decode(string& str, int idx){
    string res = tobinary(eval(str[idx])) + tobinary(eval(str[idx+1]));
    return res;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--){
        int t,b;
        cin >> t >> b;
        string str,s;
        while(cin >> s){
            str += s;
            if(sz(str)==b*2)break;
        }
        string res;
        rep(i,sz(str)){
            string enc = decode(str,i);
            if(enc[0] == '0'){
                int len = todecimal(enc.substr(1))+1;
                res += str.substr(i+2,len*2);
                i += len*2 + 1;
            }
            else{
              int cnt = todecimal(enc.substr(1))+3;
              s = "";
              s += str[i+2], s += str[i+3];
              while(cnt--)
                  res += s;
              i += 3;
            }
        }
        cout << t <<" " << sz(res)/2<<endl;
        int st=0;
        while(st < sz(res)){
            cout << res.substr(st,min(80, sz(res)-st))<<endl;
            st += 80;
        }
    }
    return 0;
    
}





