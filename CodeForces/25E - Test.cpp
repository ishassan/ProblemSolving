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

#define MOD 2147483629 // the size of hash values
#define BASE 26 // the base used to hash the strings
#define BASEINV 412977621

ll shiftLeft(ll hash)
{
    return (hash * BASE) % MOD;
}
ll shiftRight(ll hash)
{
    return (hash * BASEINV) % MOD;
}
ll addToLeft(ll hash, ll pwr, int val)
{
    val = ((val % MOD) * (pwr % MOD)) % MOD;
    return ((val % MOD) + (hash % MOD)) % MOD;
}
ll addToRight(ll hash, int val)
{
    hash = shiftLeft(hash);
    return (hash + (val % MOD)) % MOD;
}
ll removeLeft(ll hash, ll pwr, int val)
{
    hash -= ((pwr % MOD) * (val % MOD)) % MOD;
    return ((hash % MOD) + MOD) % MOD;
}
ll removeRight(ll hash, int val)
{
    hash -= val % MOD;
    hash = ((hash % MOD) + MOD) % MOD;
    return shiftRight(hash);
}

bool isIn(string &a, string &b)  //b inside a
{

    if(sz(b) > sz(a)) return 0;
    if(sz(b) == sz(a)) return a == b;
    int n = sz(b);
    ll ha = 0, hb = 0, pwr = 1;

    rep(i, n) {
        ha = addToRight(ha, a[i] - 'a');
        hb = addToRight(hb, b[i] - 'a');
        pwr = (pwr * BASE) % MOD;
    }
    if(ha == hb) return 1;
    repa(i, n, sz(a)-1, 1) {
        ha = addToRight(ha, a[i] - 'a');
        ha = removeLeft(ha, pwr, a[i - n] - 'a');
        if(ha == hb) return 1;
    }
    return 0;
}

int getCommon(string &a, string &b, int &sub) // merge last a with first b. sub 0,1,2
{
    if(isIn(a, b)) {
        sub = 1;
        return sz(b);
    }
    if(isIn(b, a)) {
        sub = 2;
        return sz(a);
    }
    int sz = min(sz(a), sz(b));
    ll pwr = 1;
    int idx1 = sz(a) - 1, idx2 = 0, res = 0;;
    ll ha = 0, hb = 0;
    while(sz--) {
        ha = addToLeft(ha, pwr, a[idx1--]);
        hb = addToRight(hb, b[idx2++]);
        if(ha == hb) res = idx2;
        pwr = (pwr * BASE) % MOD;
    }
    sub = 0;
    return res;
}

string join(string &a, string &b, int common, int sub)
{
    if(sub == 0)
        return a + b.substr(common);
    if(sub == 1)
        return a;
    return b;
}

string arr[3];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    rep(i, 3) cin >> arr[i];
    sort(arr, arr + 3);
    int mn = 1 << 27;
    do {
        int sub;
        int common = getCommon(arr[0], arr[1], sub);
        string c = join(arr[0], arr[1], common, sub);
        common = getCommon(c, arr[2], sub);
        string d = join(c, arr[2], common, sub);
        mn = min(mn, sz(d));
    } while(next_permutation(arr, arr + 3));

    cout << mn;

//     string s1 = "ca";
//     string s2 = "abcba";
//     cout << isIn(s2, s1);
//     int sub = 0;
//     cout << getCommon(s1, s2, sub);
//     cout << " " << sub;
    return 0;
}
