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

char arr[103][10005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vi> v(n);
    bool fail=0;
    rep(i, n) {
        scanf("%s", arr[i]);
        rep(j, m) {
            if(arr[i][j] == '1')
                v[i].push_back(j);
        }
        if(sz(v[i]) == 0)
            fail=1;
    }
    if(fail){
        cout << -1;
        return 0;
    }

    int res = 1 << 27;
    rep(j, m) {
        int tmp = 0;
        rep(i, n) {
            int ge = lower_bound(all(v[i]), j) - v[i].begin();
            if(ge == sz(v[i]))
                ge = 0;
            int ls = ge == 0 ? sz(v[i]) - 1 : ge - 1;
            ge = v[i][ge];
            ls = v[i][ls];
            int mn1 = ge >= j ? ge - j : m - j + ge;
            int mn2 = ls <= j ? j - ls : m - ls + j;
            tmp += min(mn1, mn2);
        }
        res = min(res, tmp);
    }


    cout << res;

    return 0;
}
