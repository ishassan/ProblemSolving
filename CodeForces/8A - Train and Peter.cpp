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

#define MAX 100010
char pat[MAX];
char text[MAX];
int pre[MAX];
vector<int> res;
int dp[MAX][30];
int getlen(int l, char c)
{
    int &m = dp[l][c-'a'];
    if(m != -1) return m;
    while(l && pat[l] != c)
        l = pre[l - 1];
    if(pat[l] == c)
        l++;
    return m = l;
}

void compute_pre()
{
    pre[0] = 0;
    int l = 0;
    if(pat[0])
        for(int i = 1; pat[i]; ++i) {
            l = getlen(l, pat[i]);
            pre[i] = l;
        }
}
void match()
{
    mem(dp, -1);
    compute_pre();
    res.clear();
    int l = 0;
    for(int i = 0; text[i]; ++i) {
        l = getlen(l, text[i]);
        if(!pat[l]) {
            res.push_back(i - l + 1);
            l = pre[l - 1]; //l=0 if no overlap is allowed
        }
    }
}
int sfind(string &p, bool first)
{
    strcpy(pat, p.c_str());
    match();
    if(sz(res) == 0) {
        return -1;
    }
    return first ? res[0] : res.back();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    string a, b;
    cin >> text >> a >> b;
    bool ab = 0, ba = 0;
    int apos = sfind(a, 1);
    int bpos = sfind(b, 0);

    if(apos > -1 && bpos > -1 && bpos >= apos+sz(a)) ab = 1;

    reverse(all(a)), reverse(all(b));
    swap(a, b);
    apos = sfind(a, 1);
    bpos = sfind(b, 0);
    if(apos > -1 && bpos > -1 && bpos >= apos+sz(a)) ba = 1;
    if(ab && ba) cout << "both";
    else if(ab && !ba) cout << "forward";
    else if(!ab && ba) cout << "backward";
    else cout << "fantasy";

    return 0;
}
