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

vs v,res;
bool isamp(string& str){
    sstr ss(str);
    string x;
    ss >> x;
    return sz(x) && x[0]=='#';
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    string str;
    while(getline(cin,str))
        v.push_back(str);

    bool prevpwr = 1;
    rep(i,sz(v)){
        str = "";
        sstr ss(v[i]);
        ss >> str;
        if(sz(str) && str[0]=='#'){
            res.push_back(v[i]);
            prevpwr = 1;
            continue;
        }
        if(sz(str) == 0){
            string st = sz(res)?res.back():"#";
            string en = i+1<sz(v)?v[i+1]:"#";
            if(isamp(st) && isamp(en))
                res.push_back(str);
            else
                continue;

        }
        else{
            string tot = str;
            while(ss >> str) tot += str;
            if(!prevpwr) res[sz(res)-1] += tot;
            else res.push_back(tot);
            prevpwr = 0;
        }
    }

    rep(i,sz(res))
        cout << res[i] << "\n";
}





