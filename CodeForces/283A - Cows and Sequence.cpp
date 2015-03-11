#include <bits/stdc++.h>

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

struct SegTree {
    int n;
    vector<pair<ll, ll> > segtree;
    //first: total sum of the whole range
    //second: node value. One value to be added to each node in the range

    SegTree() {}
    SegTree(int n) {
        this->n = n;
        int siz = 1 << (int) ceil(log(2.0 + n) / log(2.)); //nearest power of 2 for #leafs
        segtree.resize(2 * siz + 2, mp(0, 0));
    }

    //The rest of the code is problem dependent. Change it according to the problem
    ll setVal(int s, int e, ll val) {
        return setVal(0, s, e, 0, n - 1, val);
    }

    ll setVal(int idx, int tars, int tare, int curs, int cure, ll val) {
        if(tars > cure || tare < curs) return 0; //if current node is out of the target range

        if(tars <= curs && tare >= cure) { //if current node is completely inside the target range
            segtree[idx].second += val;
            segtree[idx].first += val * (cure - curs + 1);
            return val * (cure - curs + 1);
        }
        ll val1 = setVal(2 * idx + 1, tars, tare, curs, (curs + cure) / 2, val);
        ll val2 = setVal(2 * idx + 2, tars, tare, (curs + cure) / 2 + 1, cure, val);

        segtree[idx].first += val1 + val2;
        return val1 + val2;
    }

    ll getSum(int s, int e) {
        return getSum(0, s, e, 0, n - 1);
    }

    ll getSum(int idx, int tars, int tare, int curs, int cure) {
        if(tars > cure || tare < curs) return 0; //if current node is out of the target range

        if(tars <= curs && tare >= cure) { //if current node is completely inside the target range
            return segtree[idx].first;
        }
        ll val1 = getSum(2 * idx + 1, tars, tare, curs, (curs + cure) / 2);
        ll val2 = getSum(2 * idx + 2, tars, tare, (curs + cure) / 2 + 1, cure);

        ll st = max(tars, curs), en = min(tare, cure);
        return val1 + val2 + segtree[idx].second * (en - st + 1);
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int n, len = 1;
    scanf("%d", &n);
    SegTree seg(n+5);
    rep(i, n) {
        int t, x, a;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d%d", &a, &x);
            seg.setVal(0, a - 1, x);
        } else if(t == 2) {
            scanf("%d", &a);
            seg.setVal(len, len, a);
            ++len;
        } else {
            ll val = seg.getSum(len - 1, len - 1);
            seg.setVal(len - 1, len - 1, -val);
            --len;
        }
        printf("%.6lf\n", (1.0 * seg.getSum(0, len - 1)) / len);
    }
    return 0;
}