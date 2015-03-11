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
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
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
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
#define itr(A,B) typeof(B) A = B
typedef long long ll;
using namespace std;

vi res;
int bi[]={-1,1};
void bfs(int mn, vi& v){
    queue<int> q;
    res = vi(sz(v),-1<<27);
    rep(i,sz(v)){
        if(v[i] == mn)
            q.push(i), res[i]=1;
    }
    while(q.size()){
        int idx = q.front();
        q.pop();
        rep(d,2){
            int nwidx = idx + bi[d];
            if(nwidx >= sz(v) || nwidx < 0) continue;
            if(v[nwidx] > v[idx]){
                res[nwidx] = max(res[nwidx], res[idx]+1);
                q.push(nwidx);
            }
            else if(res[nwidx] < 1) {
                res[nwidx] = 1;
                q.push(nwidx);
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vi v(n);
    int mn = 1<<27;
    rep(i,n){
        cin >> v[i];
        mn = min(mn,v[i]);
    }

    bfs(mn,v);
    cout << accumulate(all(res),0);

}





