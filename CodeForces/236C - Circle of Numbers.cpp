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

int n;
vector<vi> adjlst;
vi res;
int dir[] = { -2, -1, 1, 2};
set<int> vis;
bool findRes(int adj, int i, int lim)
{
    rep(d, lim) {
        int idx = (i + dir[d] + n) % n;
        if(res[idx] == adj) return 1;
    }
    return 0;
}
bool valid()
{
    vis.clear();
    vis.insert(res[0]), vis.insert(res[1]), vis.insert(res[2]), vis.insert(res[n - 1]), vis.insert(res[n - 2]);
    repa(i, 1, n - 5, 1) {
        int num = res[i];
        int mis = -1, cnt = 0;
        rep(j, sz(adjlst[num])) {
            int adj = adjlst[num][j];
            if(findRes(adj, i, 3)) continue;
            ++cnt;
            mis = adj;
        }
        if(cnt != 1) return 0;
        if(res[(i + 2) % n] > -1 && res[(i + 2) % n] != mis) return 0;
        if(vis.count(mis)) continue;
        res[(i + 2) % n] = mis;
    }
    repa(i, n - 4, n - 1, 1) {
        int num = res[i];
        rep(j, sz(adjlst[num])) {
            int adj = adjlst[num][j];
            if(findRes(adj, i, 4)) continue;
            return 0;
        }
    }
    return 1;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    scanf("%d", &n);
    adjlst.resize(n + 5);
    int a, b;
    rep(i, 2 * n) {
        scanf("%d%d", &a, &b);
        adjlst[a].push_back(b);
        adjlst[b].push_back(a);
    }
    repa(i, 1, n, 1) if(sz(adjlst[i]) != 4) {
        printf("-1");
        return 0;
    }
    vi one = adjlst[1];
    sort(all(one));
    do {
        res = vector<int>(n, -1);
        res[n - 2] = one[0], res[n - 1] = one[1], res[0] = 1, res[1] = one[2], res[2] = one[3];
        if(valid()) {
            rep(i, n) printf("%d ", res[i]);
            return 0;
        }

    } while(next_permutation(all(one)));
    printf("-1");
    return 0;
}
