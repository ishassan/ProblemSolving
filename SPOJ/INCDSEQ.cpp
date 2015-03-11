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

int mod = 5000000;
struct BIT {
    vector<long long> v;
    BIT() {
        v.resize(1 << 14, 0);
    }
    long long getCum(int idx, int mod) {//inclusive
        idx++;
        long long r = 0;
        while(idx) {
            r += v[idx - 1];
            if(r > mod) r %= mod;
            idx -= idx & -idx;
        }
        return r;
    }
    void update(int idx, long long val) {
        idx++;
        while(idx <= (int) v.size()) {
            v[idx - 1] += val;
            idx += idx & -idx;
        }
    }
    int getIdx(long long cum) { //last occurence of cum
        int s = 0;
        int m = v.size() >> 1;
        while(m) {
            if(v[s + m - 1] <= cum)
                cum -= v[(s += m) - 1];
            m >>= 1;
        }
        return cum ? -1 : s - 1;
    }
    int lower_bound(long long cum) { //first cumulative value >= cum
        int s = 0;
        int m = v.size() >> 1;
        while(m) {
            if(v[s + m - 1] < cum)
                cum -= v[(s += m) - 1];
            m >>= 1;
        }
        return  s;
    }
    long long operator[](int idx) {
        long long res = getCum(idx, mod) - getCum(idx - 1, mod);
        if(res < 0) res %= mod;
        return res;
    }
};

BIT bit[51]; //bit[i][j]: how many sequences of length i and ends with value j
int arr[10002];
int last[10002];
map<int, int> id;
ll memo[51][10002];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    rep(i, n) {
        scanf("%d", arr + i);
        id[arr[i]];
    }
    int cnt = 0;
    repi(it, id)
    it->second = cnt++;

    rep(i, n) {
        arr[i] = id[arr[i]];
        last[arr[i]] = i;
    }

    ll res = 0;
    rep(i, n) {
        int idx = arr[i];
        if(memo[1][idx] == 0) {
            bit[1].update(idx, 1);
            memo[1][idx] = 1;
        }
        repa(j, 2, k, 1) {
            int newval = bit[j - 1].getCum(idx - 1, mod);
            int replaceVal = newval - memo[j][idx];
            bit[j].update(idx, replaceVal); //replace new result with old, not adding
            memo[j][idx] += replaceVal;

        }
        if(last[idx] == i) {
            res += memo[k][idx];
            res %= mod;
        }
    }
    printf("%lld\n", res);

    return 0;
}