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


int n;
int memo[90][90][15];

int di[] = {0,0,1,1,-1,-1};
int dj[] = {2,-2,-1,1,1,-1};

int DP(int i, int j, int rem)
{
    if(rem == 0)
        return i == 40 && j == 40;
    int &m = memo[i][j][rem];
    if(m != -1) return m;
    m = 0;
    rep(d, 6){
        int ni = i + di[d];
        int nj = j + dj[d];
        m += DP(ni, nj, rem-1);
    }
    return m;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
#endif

    int tst;
    cin >> tst;
    while(tst--) {
        cin >> n;
        mem(memo, -1);
        cout << DP(40,40,n)<<endl;
    }
    return 0;
}
