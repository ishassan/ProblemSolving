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
};

BIT bit;
map<pii, vi> mapp;
int res[300003];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    int n,a,b,mx=0;
    scanf("%d", &n);
    
    rep(i, n) {
        scanf("%d%d", &a, &b);
        mapp[mp(a,b)].push_back(i);
        mx = max(mx, b);
    }
    bit = BIT(mx+2);
    repi(it,mapp){
        int r = bit.getCum(it->first.second);
        vi& v = it->second;
        bit.update(it->first.second, v.size());
        repi(i,v) res[*i] = r;
    }
    rep(i,n) printf("%d\n",res[i]);
    return 0;
}