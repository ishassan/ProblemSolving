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

struct state {
    int arr[3];
    int prev, cur;
};
char g[77][77];
bool vis[72][72][72];
int tar[3] = {0, 1, 2};
int prevIdx[360000];
vector<state> q;
vector<pii> path;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int n;
    scanf("%d", &n);
    state st;
    scanf("%d%d%d", &(st.arr[0]), &(st.arr[1]), &(st.arr[2]));
    rep(i,3) st.arr[i]--;
    st.prev = -1, st.cur = -1;
    rep(i, n) {
        scanf("%s", g[i]);
    }

    q.push_back(st);
    vis[st.arr[0]][st.arr[1]][st.arr[2]] = 1;
    mem(prevIdx, -1);
    int steps = 0, idx = 0;
    bool yes = 0;
    while(idx < q.size()) {
        int siz = q.size();
        for(; idx < siz; idx++) {
            st = q[idx];
            if(!memcmp(st.arr, tar, sizeof(tar))) {
                yes = 1;
                goto end;
            }
            state stnxt;
            rep(i, 3) {
                int n1 = st.arr[i];
                int n2 = st.arr[(i + 1) % 3];
                int n3 = st.arr[(i + 2) % 3];
                rep(x, n) {
                    if(find(st.arr, st.arr + 3, x) < (st.arr + 3)) continue;
                    if(g[n1][x] != g[n2][n3])continue;
                    int nxt[] = {x, n2, n3};
                    sort(nxt, nxt + 3);
                    if(vis[nxt[0]][nxt[1]][nxt[2]]) continue;
                    vis[nxt[0]][nxt[1]][nxt[2]] = 1;
                    memcpy(stnxt.arr,nxt,sizeof(nxt));
                    stnxt.prev = n1, stnxt.cur = x;
                    q.push_back(stnxt);
                    prevIdx[q.size() - 1] = idx;
                }
            }

        }
        steps++;
    }
end:
    if(!yes) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", steps);
    while(idx >= 0) {
        st = q[idx];
        if(st.prev == -1) break;
        path.push_back(mp(st.prev, st.cur));
        idx = prevIdx[idx];
    }
    repd(i, sz(path) - 1, 0, 1)
    printf("%d %d\n", path[i].first+1, path[i].second+1);
    return 0;
}