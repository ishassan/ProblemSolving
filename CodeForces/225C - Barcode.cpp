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

int n, m, x, y;
char g[1002][1002];
int colh[1002];
int memo[1002][1002][2];
int DP(int idx, int cnt, int lst) //lst= dot hash
{
    if(idx == m) return cnt >= x && cnt <= y ? 0 : 1e9;
    int &m = memo[idx][cnt][lst];
    if(m != -1) return m;

    int hash = colh[idx], dot = n - colh[idx];
    m = 1e9;
    if(lst == 0) {
        if(cnt < y)
            m = DP(idx + 1, cnt + 1 , lst) + hash;
        if(cnt >= x)
            m = min(m, DP(idx + 1, 1, !lst) + dot);
    } else if(lst == 1) {
        if(cnt < y)
            m = DP(idx + 1, cnt + 1 , lst) + dot;
        if(cnt >= x)
            m = min(m, DP(idx + 1, 1, !lst) + hash);
    }

    return m;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    scanf("%d%d%d%d", &n, &m, &x, &y);
    rep(i, n)
    scanf("%s", g[i]);
    rep(j, m)
    rep(i, n)
    colh[j] += g[i][j] == '#';

    mem(memo, -1);
    printf("%d", min(DP(0, 0, 0), DP(0, 0, 1)));
    return 0;
}