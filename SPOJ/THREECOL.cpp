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

char str[10002];
int memo[10002][3];
bool vis[10002];
int len;
vector<pii > nodes;

int DP(int idx, int clr, bool Min) { //RGB->012
	if (idx >= len || nodes[idx].first == idx)
		return 0;

	int& m = memo[idx][clr];
	if (m != -1)
		return m;

	int c1, c2;
	if (nodes[idx].first == nodes[idx].second && idx + 1 == nodes[idx].first) {
		c1 = DP(nodes[idx].first, (clr + 1) % 3, Min) + ((clr + 1) % 3 == 1);
		c2 = DP(nodes[idx].first, (clr + 2) % 3, Min) + ((clr + 2) % 3 == 1);
	}

	else {
		c1 = DP(nodes[idx].first, (clr + 1) % 3, Min) + ((clr + 1) % 3 == 1);
		c1 += DP(nodes[idx].second, (clr + 2) % 3, Min) + ((clr + 2) % 3 == 1);

		c2 = DP(nodes[idx].first, (clr + 2) % 3, Min) + ((clr + 2) % 3 == 1);
		c2 += DP(nodes[idx].second, (clr + 1) % 3, Min) + ((clr + 1) % 3 == 1);
	}

	return m = Min ? min(c1, c2) : max(c1, c2);
}

pii getChild(int idx) {
	if (vis[idx])
		return nodes[idx];
	vis[idx] = 1;

	if (str[idx] == '0') {
		return nodes[idx] = mp(idx,idx);
	}

	if (str[idx] == '1') {
		nodes[idx] = mp(idx+1,idx+1);
		return getChild(idx+1);
	}

	else{
		int scnd = getChild(idx+1).second+1;
		 nodes[idx] = mp(idx+1, scnd);
		 return getChild(scnd);
	}
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		mem(vis,0);
		scanf("%s", str);
		len = strlen(str);
		nodes.clear();
		nodes.resize(len);

		rep(i,len)
			if (!vis[i])
				getChild(i);

//		rep(i,len)
//			cerr<<i<<": "<<nodes[i].first<<","<<nodes[i].second<<endl;

		mem(memo,-1);
		int mn = min(DP(0, 0, 1), min(DP(0, 1, 1) + 1, DP(0, 2, 1)));
		mem(memo,-1);
		int mx = max(DP(0, 0, 0), max(DP(0, 1, 0) + 1, DP(0, 2, 0)));

		printf("%d %d\n", mx, mn);

	}
	return 0;
}
