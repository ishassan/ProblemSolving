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

vi lvl[100005];
vi adjlst[100005];
bool vis[100005];
int lvlidx[100005];
vector<pii> res;
vi v;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    v.resize(n);
    rep(i, n) {
        scanf("%d", &v[i]);
        lvl[v[i]].push_back(i);
    }
    if(sz(lvl[0]) != 1) {
        printf("-1");
        return 0;
    }
    queue<pii> q;
    int idx = lvl[0].front();
    q.push(mp(idx, 0));
    vis[idx] = 1;
    while(q.size()) {
        pii p = q.front();
        q.pop();
        int l = p.second + 1;
        int cnt = sz(adjlst[p.first]);
        for(int i = lvlidx[l]; i < sz(lvl[l]) && cnt < k; i++, lvlidx[l]++) {
            int node = lvl[l][i];
            if(vis[node]) continue;
            vis[node] = 1;
            adjlst[p.first].push_back(node);
            adjlst[node].push_back(p.first);
            ++cnt;
            q.push(mp(node, l));
        }

    }
    rep(i, n) {
        if(!vis[i] || sz(adjlst[i]) > k) {
            printf("-1");
            return 0;
        }
    }
    rep(i, n) {
        rep(j, sz(adjlst[i])) {
            if(i + 1 < adjlst[i][j] + 1)
                res.push_back(mp(i + 1, adjlst[i][j] + 1));
        }
    }
    printf("%d\n", sz(res));
    rep(i, sz(res)) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}