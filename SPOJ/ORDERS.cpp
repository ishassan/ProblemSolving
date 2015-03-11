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

struct BIT {
    vector<long long> v;
    BIT() {
    }
    BIT(int s) {
        s = 1 << (int) ceil(log(2.0 + s) / log(2.));
        v.resize(s, 0);
    }

    long long getCum(int idx) {//inclusive
        idx++;
        long long r = 0;
        while(idx) {
            r += v[idx - 1];
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
    int getIdx(long long cum) { //first occurence of cum
        int s = 0;
        int m = v.size() >> 1;
        while(m) {
            if(v[s + m - 1] < cum)
                cum -= v[(s += m) - 1];
            m >>= 1;
        }
        return  s;
    }
};

BIT bit;
int res[200002], arr[200002];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    int tst;
    scanf("%d", &tst);
    while(tst--) {
        int n;
        scanf("%d", &n);
        bit = BIT(n + 2);
        rep(i, n) {
            scanf("%d", &arr[i]);
            bit.update(i, 1);
        }

        repd(i, n - 1, 0, 1) {
            int idx = bit.getIdx(i + 1 - arr[i]);
            res[i] = idx+1;
            bit.update(idx, -1);
        }
        char *s = "";
        rep(i, n) {
            printf("%s%d", s, res[i]), s = " ";
        }
        printf("\n");

    }

    return 0;
}