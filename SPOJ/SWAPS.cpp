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
#include <complex>
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
    int v[50002];
    int s;
    BIT() {
    }
    BIT(int s) {
        this->s = s;
    }

    int getCum(int idx) {//inclusive
        idx++;
        int r = 0;
        while(idx) {
            r += v[idx - 1];
            idx -= idx & -idx;
        }
        return r;
    }
    void update(int idx, int val) {
        idx++;
        while(idx <= s) {
            v[idx - 1] += val;
            idx += idx & -idx;
        }
    }
};

int nseg, lenseg;
int siz = 50000;

struct BIT2D {
    int v[513][50002];
    BIT2D() {
    }

    int getCum(int i, int j) {//inclusive
        i++, j++;
        int r = 0;
        while(i) {
            int jj = j;
            while(jj) {
                r += v[i - 1][jj - 1];
                jj -= jj & -jj;
            }
            i -= i & -i;
        }
        return r;
    }
    void update(int i, int j, int val) {
        if(i < 0 || j < 0) return;
        i++, j++;
        while(i <= nseg) {
            int jj = j;
            while(jj <= siz) {
                v[i - 1][jj - 1] += val;
                jj += jj & -jj;
            }
            i += i & -i;
        }
    }
};

BIT normal(siz);
BIT2D les, mor;
int arr[250002];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    nseg = sqrt(n);
    lenseg = (n + nseg - 1) / nseg;

    long long res = 0;
    rep(i, n) {
        scanf("%d", arr + i);
        normal.update(siz - arr[i], 1);
        res += normal.getCum(siz - arr[i] - 1);
        les.update(nseg - 1 - i / lenseg, arr[i], 1);
        mor.update(i / lenseg, siz - arr[i], 1);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int idx, val;
        scanf("%d%d", &idx, &val), --idx;
        int curseg = idx / lenseg;
        int st = curseg * lenseg, en = min(st + lenseg, n);
        repa(i, st, idx - 1, 1)
        res += (arr[i] > val) - (arr[i] > arr[idx]);
        repa(i, idx + 1, en - 1, 1)
        res += (arr[i] < val) - (arr[i] < arr[idx]);

        res += mor.getCum(curseg - 1, siz - val - 1) - mor.getCum(curseg - 1, siz - arr[idx] - 1);
        res += les.getCum(nseg - 1 - curseg - 1, val - 1) - les.getCum(nseg - 1 - curseg - 1, arr[idx] - 1);

        mor.update(curseg, siz - arr[idx], -1);
        mor.update(curseg, siz - val, 1);
        les.update(nseg - 1 - curseg , arr[idx], -1);
        les.update(nseg - 1 - curseg , val, 1);
        arr[idx] = val;
        printf("%lld\n", res);
    }

    return 0;
}