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
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int n;
vector<vi> bi(100002), adj(100002);
bool vis[100002] = { 0 };
int memo[100002];
void DFS(int idx) {
	repi(i,bi[idx]) {
		if (!vis[*i])
			vis[*i] = 1, adj[idx].push_back(*i), DFS(*i);
	}
}
int DP(int idx){
	if(memo[idx]>-1)
		return memo[idx];
	int c1 = 1;
	repi(i,adj[idx])
		c1 += DP(*i);
	int c2 = sz(adj[idx]);
	repi(i, adj[idx])
		repi(j,adj[*i])
			c2 += DP(*j);
	return memo[idx] = min(c1,c2);
}
int main() {

	scanf("%d", &n);
	int u, v;
	rep(i,n-1) {
		scanf("%d%d", &u, &v);
		bi[u - 1].push_back(v - 1);
		bi[v - 1].push_back(u - 1);
	}
	vis[0] = 1;
	DFS(0);
	mem(memo,-1);
	printf("%d\n",DP(0));
	return 0;
}
