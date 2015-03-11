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

struct state {
    int idx, x, y;
    state() {}
    state(int midx, int mx, int my) {
        idx = midx, x = mx, y = my;
    }
};

//min2max1
bool min2max1(const state &st1, const state &st2)
{
    if(st1.y < st2.y) return 1;
    if(st1.y > st2.y) return 0;
    if(st1.x > st2.x) return 1;
    else return 0;
}
bool cmpmax(const state &st1, const state &st2)
{
    return st1.x > st2.x;
}
int main()
{
//     #ifndef ONLINE_JUDGE
//     freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
//     #endif
    


    int n, p, k;
    scanf("%d%d%d", &n, &p, &k);
    vector<state> v(n);
    rep(i, n) {
        v[i].idx = i;
        scanf("%d%d", &(v[i].x), &(v[i].y));
    }
    sort(all(v), min2max1);
    priority_queue<pii, vector<pii>, greater<pii > > pq;
    ll mx = 0, bsti, sum = 0;
    repd(i, n - 1, n - k, 1) {
        pq.push(mp(v[i].x, v[i].idx));
        sum += v[i].x;
    }
    bsti = n - k, mx = sum;
    repd(i, n - k - 1, p - k, 1) {
        if(v[i].x > pq.top().first) {
            sum -= pq.top().first;
            pq.pop();
            pq.push(mp(v[i].x, v[i].idx));
            sum += v[i].x;
            if(sum > mx) {
                mx = sum;
                bsti = i;
            }
        }
    }
    int am = p - k;
    repa(i, bsti - am, bsti - 1, 1) cout << v[i].idx + 1 << " ";
    sort(v.begin()+bsti,v.end(),cmpmax);
    while(k--){
         cout << v[bsti++].idx+1 << " ";
    }
//     cout << "\n::"<<mx;
    return 0;
}
