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

map<int, pii> memo[300005];
int pre[100003], res[100003];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    int n;
    scanf("%d", &n);
    int mx = -1, lst=0;
    repa(i, 1, n, 1) {
        int v, c, l, r;
        scanf("%d%d%d%d", &v, &c, &l, &r);
        if(l == 0 || memo[c + l + r].count(l)) {
            pii val_idx = memo[c + l + r][l];
            if(val_idx.first + v > memo[c + l + r][c + l].first) {
                memo[c + l + r][c + l].first = val_idx.first + v;
                memo[c + l + r][c + l].second = i;
                pre[i] = val_idx.second;
                if(r == 0 && val_idx.first + v > mx) {
                    mx = val_idx.first + v;
                    lst = i;
                }
            }
        }
    }
    int len = 0;
    for(; lst; lst = pre[lst]) res[len++] = lst;
    printf("%d\n", len);
    while(len--) printf("%d ", res[len]);
    return 0;
}