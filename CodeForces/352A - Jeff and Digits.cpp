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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
#endif

    int n, x;
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cnt5 = 0, cnt0 = 0;
    rep(i, n) {
        cin >> x;
        if(x == 0) cnt0++;
        else cnt5++;
    }
    if(cnt0 == 0) {
        cout << -1;
        return 0;
    }
    while(cnt5) {
        if((cnt5 * 5) % 9 == 0) {
            rep(i, cnt5) cout << 5;
            rep(i, cnt0) cout << 0;
            return 0;
        }
        cnt5--;
    }
    cout << 0;


    return 0;
}
