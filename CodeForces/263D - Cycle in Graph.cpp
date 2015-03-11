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

int n,m,k;
vector<vi> adjlst;
bool vis[100005];
vi path;
void dfs(int cur, int prev){
    if(vis[cur]){
        int idx = myfind(path,cur);
        if(sz(path)-idx <= k) return;
        printf("%d\n",sz(path)-idx);
        repa(i,idx,sz(path)-1,1) printf("%d ",path[i]);
        exit(0);
    }
    vis[cur]=1;
    path.push_back(cur);
    repi(it, adjlst[cur]){
        if((*it)==prev) continue;
        dfs(*it,cur);
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    scanf("%d%d%d",&n,&m,&k);
    adjlst.resize(n+5);
    int a,b;
    rep(i,m){
        scanf("%d%d",&a,&b);
        adjlst[a].push_back(b);
        adjlst[b].push_back(a);
    }
    dfs(1,-1);
    return 0;
}