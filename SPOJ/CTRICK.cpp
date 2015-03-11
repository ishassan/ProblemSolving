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
    BIT() {}
    BIT(int s) {
        s = 1 << (int) ceil(log(2.0 + s) / log(2.));
        v.resize(s, 0);
    }

    long long get(int i) {
        i++;
        long long r = 0;
        while(i) {
            r += v[i - 1];
            i -= i & -i;
        }
        return r;
    }
    void add(int i, long long val) {
        i++;
        while(i <= (int) v.size()) {
            v[i - 1] += val;
            i += i & -i;
        }
    }
    int find(long long val) {
        int s = 0;
        int m = v.size() >> 1;
        while(m) {
            if(v[s + m - 1] < val)
                val -= v[(s += m) - 1];
            m >>= 1;
        }
        return s;
    }
};

struct BITMultiSet: public BIT {

    BITMultiSet(): BIT() {}
    // the max value that can be stored in the set
    BITMultiSet(int maxVal): BIT(maxVal) {
        add(0, -1);
    }

    void insert(int val) {
        add(val, 1);
    }

    void eraseByVal(int val) {
        add(val, -1);
    }

    void eraseByIndex(int ind) {
        eraseByVal((*this)[ind]);
    }

    int operator[](int ind) {
        return find(ind);
    }

    int count(int val) {
        return get(val) - get(val - 1);
    }

    bool empty() {
        return get(v.size() - 1) == -1;
    }

    int size() {
        return get(v.size() - 1) + 1;
    }
};
BITMultiSet st;
int res[20003];

void print()
{
    rep(i, st.size())
    cout << st[i] << " ";
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    int tst;
    scanf("%d", &tst);
    while(tst--) {
        int n;
        scanf("%d", &n);
        mem(res, 0);
        st = BITMultiSet(n + 2);
        rep(i, n) st.insert(i);
        int cur = 0;
        repa(i, 1, n, 1) {
//             print();
            cur = (cur + i) % st.size();
            res[st[cur]] = i;
            st.eraseByIndex(cur);
        }
        char *s = "";
        rep(i, n)
        printf("%s%d", s, res[i]), s = " ";
        printf("\n");
    }

    return 0;
}