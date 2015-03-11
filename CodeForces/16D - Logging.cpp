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
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    int n;
    cin >> n;
    string str;
    getline(cin,str);
    int cnt=0,t=10000,res=0;
    rep(i,n){
        getline(cin,str);
        int h,m;
        char c;
        sscanf(str.c_str(), "[%d:%d %c",&h,&m,&c );
        if(c=='p'){
            if(h<12)
                h+=12;
        }
        else{
            if(h==12)h=0;
        }
        h = h*60+m;
        if(h < t){
            ++res;
            t = h;
            cnt=1;
        }
        else if(h==t){
            if(++cnt > 10){
                cnt=1;
                ++res;
            }
        }
        else{
            t=h;
            cnt=1;
        }
    }
    cout << res;

    return 0;
}
