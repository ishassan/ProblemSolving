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

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

typedef long long ll;
using namespace std;

int n;
ll memo[200003][2];
ll arr[200003];
int opr[2] = {1, -1};
bool vis[200003][2];
ll DP(int x, bool sub)
{
    if(x < 1 || x > n) return 0;
    if(vis[x][sub]) return -1LL << 60;
    ll &m = memo[x][sub];
    if(m != -1) return m;
    vis[x][sub] = 1;
    m = DP(x + arr[x] * opr[sub], !sub) + arr[x];
    vis[x][sub] = 0;
    return m;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif
    mem(memo, -1);

    scanf("%d", &n);
    repa(i, 1, n - 1, 1) scanf(LL, arr + i + 1);
    repa(i, 1, n - 1, 1) {
        arr[1]=i;
        ll res = DP(1 + i, 1) + i;
        printf(LL "\n", max(res, -1LL));
    }
    return 0;
}