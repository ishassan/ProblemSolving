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

string str, heavy = "heavy", metal = "metal";
bool cnt(int idx)
{
    if(str[idx] == 'h') {

    }
    if(str[idx] == 'm') {
        rep(i, 5) {
            if(idx + i < sz(str) && str[idx + i] == metal[i]) continue;
            return 0;
        }
        return 1;
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif


    string str;
    cin >> str;
    vi h, m;
    rep(idx, sz(str)) {
        if(str[idx] != 'h' && str[idx] != 'm') continue;
        bool fail = 0;
        if(str[idx] == 'h') {
            rep(i, 5) {
                if(idx + i >= sz(str) || str[idx + i] != heavy[i]) {
                    fail = 1;
                    break;
                }
            }
            if(!fail) h.push_back(idx);
        } else {
            rep(i, 5) {
                if(idx + i >= sz(str) || str[idx + i] != metal[i]) {
                    fail = 1;
                    break;
                }
            }
            if(!fail) m.push_back(idx);
        }
    }
    ll res = 0;
    rep(i,sz(h)){
        res += m.end() - lower_bound(all(m), h[i]);
    }
    cout << res;
    return 0;
}
