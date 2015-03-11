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
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int n;
vector<vi> adjlst;

ll res = 0;
ll memo[1000000];
bool vis[10002];

bool isfinish(int node){
	repi(it,adjlst[node]){
		if(!vis[*it])
			return 0;
	}
	return 1;
}
ll DFS(int node) {
	if (isfinish(node)) {
		res += 1;
		return 1;
	}

	if (memo[node] != -1)
		return memo[node];

	ll cur = 0;
	vis[node] = 1;
	rep(i, sz(adjlst[node])) {
		if (!vis[adjlst[node][i]])
			cur += DFS(adjlst[node][i]) + 1;
	}
	++cur;
	res += cur;
	return memo[node] = cur;
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		mem(memo,-1);
		mem(vis,0);
		scanf("%d", &n);
		adjlst.clear();
		adjlst.resize(n + 5);
		res = 0;
		int a, b;
		reps(i,1,n) {
			scanf("%d%d", &a, &b);
			adjlst[a].push_back(b);
			adjlst[b].push_back(a);
		}

		DFS(0);
		printf("%lld\n", res);

	}

	return 0;
}
