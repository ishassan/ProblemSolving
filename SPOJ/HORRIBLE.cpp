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
#define pll pair<ll,ll>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;

struct SegTree {
    int n;
    vector<pll> segtree; //total sum, node val

    SegTree() {}
    SegTree(int n) {
        this->n = n;
        int siz = 1 << (int) ceil(log(2.0 + n) / log(2.)); //nearest power of 2 for #leafs
        segtree.resize(2 * siz + 2, mp(0, 0));
    }
    ll setVal(int s, int e, ll val) {
        return setVal(0, s, e, 0, n - 1, val);
    }
    ll setVal(int idx, int tars, int tare, int curs, int cure, ll val) {
        if(tars > cure || tare < curs) return segtree[idx].first; //if out of range. Edit here

        if(tars <= curs && tare >= cure) {
            segtree[idx].second += val;
            segtree[idx].first += val * (cure - curs + 1);
            return segtree[idx].first;
        }
        ll val1 = setVal(2 * idx + 1, tars, tare, curs, (curs + cure) / 2, val);
        ll val2 = setVal(2 * idx + 2, tars, tare, (curs + cure) / 2 + 1, cure, val);

        segtree[idx].first = val1 + val2 + segtree[idx].second*(cure-curs+1);
        return segtree[idx].first;
    }

    ll getSum(int s, int e) {
        return getSum(0, s, e, 0, n - 1);
    }
    ll getSum(int idx, int tars, int tare, int curs, int cure) {
        if(tars > cure || tare < curs) return 0; //if out of range. Edit here

        if(tars <= curs && tare >= cure) {
            return segtree[idx].first;
        }
        ll val1 = getSum(2 * idx + 1, tars, tare, curs, (curs + cure) / 2);
        ll val2 = getSum(2 * idx + 2, tars, tare, (curs + cure) / 2 + 1, cure);

        ll st=max(tars,curs), en = min(tare,cure);
        return val1 + val2 + segtree[idx].second*(en-st+1);
    }
};

SegTree tree;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    int tst;
    scanf("%d", &tst);
    while(tst--) {
        int n, c;
        scanf("%d%d", &n, &c);
        tree = SegTree(n);
        int t, s, e, val;
        rep(i, c) {
            scanf("%d", &t);
            if(t == 0) {
                scanf("%d%d%d", &s, &e, &val);
                tree.setVal(s - 1, e - 1, val);
            } else {
                scanf("%d%d", &s, &e);
                ll res = tree.getSum(s - 1, e - 1);
                printf("%lld\n", res);
            }
        }
    }
    return 0;
}