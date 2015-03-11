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
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define mem(a,n) memset((a), (n), sizeof(a))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

vector<pii> g[6];
int memo[10][1005];
int DP(int idx, int rem) {
	if (idx == 6)
		return 1e6;

	int& m = memo[idx][rem];
	if (m != -1)
		return m;

	m = 0;
	rep(i,sz(g[idx])) {
		if (rem < g[idx][i].first)
			continue;

		int res = min(g[idx][i].second, DP(idx + 1, rem - g[idx][i].first)); //minimum of current and next quality
		m = max(m, res);
	}

	return m;
}
int main() {
	int n, m, typ, pr, q;
	scanf("%d%d", &n, &m);
	rep(i,n) {
		scanf("%d%d%d", &typ, &pr, &q);
		g[typ - 1].push_back(mp(pr,q));
	}

	mem(memo,-1);
	printf("%d\n", DP(0, m));
	return 0;
}
