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


string tobinary(int n){
    string res;
    while(n){
        res += (n%2) + '0';
        n /= 2;
    }
    reverse(all(res));
    while(sz(res) < 7) res = "0"+res;
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

string encode(string& str){
    int a = todecimal(str.substr(0,4));
    int b = todecimal(str.substr(4,4));
    string res="";
    res += a>=10?(a-10+'A'):(a+'0');
    res += b>=10?(b-10+'A'):(b+'0');
    return res;
}

void repeat(int cnt, string& res, string& s){
    cnt -= 3;
    string bi = "1" + tobinary(cnt);
    res += encode(bi) + s;
}

void encodeOne(string& str, int idx, int len, string& res){
    int cnt = len/2;
    string bi = "0" + tobinary(cnt-1);
    res += encode(bi) + str.substr(idx,len);
}

int getOne(string& str, int idx){
    int cnt = 1;
    int len = 2;
    string s = str.substr(idx,2);
    idx+=2;
    while(idx < sz(str)){
        string tmp = str.substr(idx,2);
        if(tmp == s){
            len += 2;
            if(++cnt == 3){
                len -= 6;
                return len;
            }
        }
        else{
            len += 2;
            cnt = 1;
            s = tmp;
        }
        idx += 2;
    }
    return len;
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
            if(sz(str) == b*2)break;
        }
        string res;
        int i=0;
        while(i < sz(str)){
            int len = getOne(str,i);
            if(len > 0){
                len = min(len,256);
                encodeOne(str,i,len,res);
                i += len;
                continue;
            }

            int idx = i+2;
            s = str.substr(i,2);
            int cnt=1;
            while(idx < sz(str)){
                string tmp = str.substr(idx,2);
                if(tmp == s){
                    ++cnt;
                    idx += 2;
                }
                else break;
            }

            while(cnt >= 130){
                repeat(130,res,s);
                cnt -= 130;
                i += 130*2;
            }
            if(cnt >= 3)
            {
                repeat(cnt,res,s);
                i += cnt*2;
            }
        }
        cout << t << " " << sz(res)/2<<endl ;
        int st=0;
        while(st < sz(res)){
            cout << res.substr(st,min(80,sz(res)-st))<<endl;
            st += 80;
        }
    }
    
}





