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

#define BASE 128LL
#define BASEINV 1453125008LL
#define MOD 2000000011LL

int addCharAt(ll pwr, char v, int pvHashV)
{
    return ((pwr * v) + pvHashV) % MOD;
}
int removeCharAt(ll pwr, char v, int pvHashV)
{
    return (MOD - (pwr * v) + pvHashV) % MOD;
}
int shiftL(int pvHash)
{
    return (pvHash * BASE) % MOD;
}
int shiftR(int pvHash)
{
    return (pvHash * BASEINV) % MOD;
}
char str[5000004];
int memo[5000002];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

    scanf("%s", str);
    int leftH = 0, rightH = 0, hash = str[0];
    ll pwr = 1;
    int res = 1;
    
    memo[0]=1;
    for(int i = 1; str[i]; i++) {
        if((i & 1) == 0) pwr = (pwr * BASE) % MOD;
        hash = shiftL(hash);
        hash = addCharAt(1, str[i], hash);
        rightH = addCharAt(pwr, str[i], rightH);

        if(i & 1) {
            leftH = shiftL(leftH);
            leftH = addCharAt(1, str[i / 2], leftH);
        } else {
            rightH = removeCharAt(1, str[i / 2], rightH);
            rightH = shiftR(rightH);
        }
        if(leftH == rightH)
            memo[i] = 1 + memo[i & 1 ? i / 2 : i / 2 - 1];
        res += memo[i];
    }
    printf("%d", res);
    return 0;
}