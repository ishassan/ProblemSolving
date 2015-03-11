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

struct state {
	int to, cost;
	char dir;
};

state tost(int to, int c, char d) {
	state st = { to, c, d };
	return st;
}

state graph[102][5];
int sz[102];

map<int, int> m;

bool vis[102][102];

int rec(int node, char dir) {
	if (node == 0)
		return 0;

	if (node == -1)
		node = 0;

	int mn = 1 << 27;
	for (int i = 0; i < sz[node]; i++) {
		state nxt = graph[node][i];

		if(vis[node][nxt.to])
			continue;

		vis[node][nxt.to]=1;
		vis[nxt.to][node]=1;

		if (nxt.dir == dir) {
			mn = min(mn, rec(nxt.to, dir));
		}

		else
			mn = min(mn, rec(nxt.to, dir)
					+ nxt.cost);

		vis[node][nxt.to] = 0;
		vis[nxt.to][node]=0;
	}

	return mn;
}
int main() {

	int n;
	cin >> n;
	int cnt = 0, a, b, c;
	fo(i,n) {
		cin >> a >> b >> c;
		if (m.find(a) == m.end())
			m[a] = cnt++;
		if (m.find(b) == m.end())
			m[b] = cnt++;

		graph[m[a]][sz[m[a]]++] = tost(m[b], c, 'o');
		graph[m[b]][sz[m[b]]++] = tost(m[a], c, 'i');

	}

	int mn = rec(-1, 'o');
	memset(vis,0,sizeof vis);
	mn = min(mn, rec(-1,'i'));

	cout << mn << endl;

	return 0;
}
