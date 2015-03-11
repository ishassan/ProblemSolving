#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>

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
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

const int MAXN = 10100;
vector<vector<pii> > adj;
int chainNo=0,chainHead[MAXN],chainInd[MAXN]/*,chainPos[MAXN],chainSize[MAXN]*/;
int subsiz[MAXN],lvl[MAXN];
int nodepos[MAXN],costpos[MAXN], costorder[MAXN],nodeorder[MAXN*3],lvlorder[MAXN*3];
int lencostorder,lennodeorder,lenlvlorder;
int par[MAXN];
pii edges[MAXN];
int segArr[MAXN*4];

void init(int n){

    chainNo=lencostorder=lennodeorder=lenlvlorder=0;
    adj.clear(); adj.resize(n);
    mem(chainHead,-1);
 //   mem(chainSize,0);
}

//========================================
const int LOG_SIZE = 14;
int minArr[3*MAXN][LOG_SIZE];

void buildRMQ(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; ++i)
        minArr[i][0] = i;
    for (i = 1; (1 << i) <= n; ++i)
        for (j = 0; j + (1 << i) <= n; ++j){
            int a = minArr[j][i - 1];
            int b = minArr[j + (1 << (i - 1))][i - 1];
            minArr[j][i] = (arr[a] < arr[b]) ? a:b;
        }
}
int getLCA(int arr[], int st, int en) {
    int L = int(log2(en - st + 1.0) + 1e-7);
    int a = minArr[st][L];
    int b = minArr[en - (1 << L) + 1][L];
    int mnInd = (arr[a] < arr[b]) ? a:b;
    return mnInd;
}

//======================================
void prehld(int cur, int prev) {
    subsiz[cur] = 1;
    rep(i,sz(adj[cur])){
        pii nxt = adj[cur][i];
        if(nxt.first != prev) {
            prehld(nxt.first, cur);
            subsiz[cur] += subsiz[nxt.first];
        }
    }
}
void hld(int cur, int prev, int cst, int depth) {
    if(chainHead[chainNo] == -1) chainHead[chainNo]=cur;
    chainInd[cur] = chainNo;
//    chainPos[cur] = chainSize[chainNo];
//    chainSize[chainNo]++;

    lvl[cur] = depth;
    lvlorder[lenlvlorder++] = depth;
    nodepos[cur] = lennodeorder;
    nodeorder[lennodeorder++] = cur;
    costpos[cur] = lencostorder;
    costorder[lencostorder++] = cst;
    par[cur] = prev;

    int ind = -1,mx = -1;
    for(int i = 0; i < sz(adj[cur]); i++)
        if(adj[cur][i].first != prev && subsiz[ adj[cur][i].first ] > mx) {
            mx = subsiz[ adj[cur][i].first ];
            ind = i;
        }

    if(ind >= 0){
        hld( adj[cur][ind].first, cur, adj[cur][ind].second, depth+1 );
        lvlorder[lenlvlorder++] = depth;
        nodeorder[lennodeorder++] = cur;
    }

    for(int i = 0; i < sz(adj[cur]); i++) {
        if(adj[cur][i].first != prev &&  i != ind) {
            chainNo++;
            hld( adj[cur][i].first, cur, adj[cur][i].second, depth+1  );
            lvlorder[lenlvlorder++] = depth;
            nodeorder[lennodeorder++] = cur;
        }
    }
}
//====================================================

void buildSeg(int cur, int st, int en, int arr[]){
    if(st == en){
        segArr[cur] = arr[st];
        return;
    }
    int c1 = (cur<<1)+1, c2 = c1+1, mid = (st+en)>>1;
    buildSeg(c1, st, mid, arr);
    buildSeg(c2, mid+1, en, arr);
    segArr[cur] = max(segArr[c1], segArr[c2]);
}
int qx,val;
void updateSeg(int cur, int st, int en){
    if(st > qx || en < qx) return;
    if(st == en){
        segArr[cur] = val;
        return;
    }
    int c1 = (cur<<1)+1, c2 = c1+1, mid = (st+en)>>1;
    updateSeg(c1, st, mid);
    updateSeg(c2, mid+1, en);
    segArr[cur] = max(segArr[c1], segArr[c2]);
}

int qs, qe;
int querySeg(int cur, int st, int en){
    if(qs > en || qe < st) return -1;
    if(qs <= st && qe >= en) return segArr[cur];

    int c1 = (cur<<1)+1, c2 = c1+1, mid = (st+en)>>1;
    int r1 = querySeg(c1,st,mid);
    int r2 = querySeg(c2,mid+1,en);
    return max(r1,r2);
}

int getMax(int a, int b){
    if(a==b) return 0;
    int mx=0;
    while(1){
        if(chainInd[a] == chainInd[b]){
            if(a == b) break;
            qs = costpos[b]+1, qe = costpos[a];
            int res = querySeg(0,0,lencostorder-1);
            mx = max(mx, res);
            return mx;
        }
        int c = chainHead[ chainInd[a] ];
        qs = costpos[c], qe = costpos[a];
        int res = querySeg(0,0,lencostorder-1);
        mx = max(mx, res);
        a = par[c];
    }
    return mx;
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif

    int tst;
    scanf("%d",&tst);
    while(tst--){
        int n;
        scanf("%d",&n);
        init(n);
        rep(i,n-1){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            --a,--b;
            edges[i] = mp(a,b);
            adj[a].push_back(mp(b,c));
            adj[b].push_back(mp(a,c));
        }
        prehld(0,-1);
        hld(0,-1,0,0);
        buildRMQ(lvlorder, lenlvlorder);
        buildSeg(0,0,lencostorder-1,costorder);
        char str[20]={0};
        while(~scanf("%s",str)){
            if(str[0]=='D')break;
            int a,b;
            scanf("%d%d",&a,&b);
            if(str[0]=='Q'){
                --a,--b;
                int aidx = nodepos[a], bidx = nodepos[b];
                if(aidx > bidx) swap(aidx,bidx);
                int lca = nodeorder[getLCA(lvlorder,aidx,bidx)];
                printf("%d\n", max(getMax(a,lca), getMax(b,lca)));
            }
            else{
                --a;
                pii nodes = edges[a];
                int node = (lvl[nodes.first] > lvl[nodes.second])?nodes.first:nodes.second;
                qx = costpos[node];
                val = b;
                updateSeg(0,0,lencostorder-1);
            }
        }
    }

    return 0;
}
