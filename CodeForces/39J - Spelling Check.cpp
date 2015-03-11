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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

string a, b;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
#endif

    cin >> a >> b; b+="*";
    int i = 0, j = 0,cnt=0,idx=-1;
    while(i < sz(a) && j < sz(b)) {
        if(a[i] == b[j]) {
            ++i, ++j;
            continue;
        }
        if(++cnt > 1) break;
        idx = i;
        ++i;
    }
    if(cnt > 1){cout << 0; return 0;}
    cnt=0;
    char c=a[idx];
    while(idx>=0 && a[idx]==c){++cnt;--idx;}
    cout << cnt << endl;
    ++idx;
    while(cnt--){ cout << ++idx << " ";}
    return 0;
}
