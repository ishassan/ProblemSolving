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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

int cost[100002];
vector<pii> tree[100002];
set<int> nodes;
bool par[100002];
int memo[100002][2];

int DP(int cur, bool taken) {

	if (memo[cur][taken] != -1)
		return memo[cur][taken];

	int res=0;

	if (taken)
		res -= cost[cur];

	if (tree[cur].size() == 0)
		return res;

	int r1=0,r2=0;
	for (int i = 0; i < tree[cur].size(); i++) {
		r1 = DP(tree[cur][i].first, 0);
		r2 = DP(tree[cur][i].first, 1);
		if (taken)
			r2 += tree[cur][i].second;
		res += max(r1,r2);
	}

	return memo[cur][taken] = res;
}
int main() {
	memset(memo, -1, sizeof memo);
	int n;

	cin >> n;
	fo(i,n)
		cin >> cost[i];

	int src, dest, cst;
	fo(i,n-1) {
		cin >> src >> dest >> cst;
		nodes.insert(src), nodes.insert(dest);
		tree[src].push_back(mp(dest,cst));
		par[dest] = 1;
	}

	for (set<int>::iterator i = nodes.begin(); i != nodes.end(); i++) {
		if (par[*i] == 0) {

			int r1 = DP(*i, 0);
			int r2 = DP(*i, 1);
			cout << max(r1, r2) << endl;
			return 0;
		}
	}

	return 0;
}
