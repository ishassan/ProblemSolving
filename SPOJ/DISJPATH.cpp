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

const int MAX = 5002;
vector<pii> adjlist[MAX];
int k, n;

int src = 1, dest = 2;
bool vis[MAX];
int par[MAX];
int paths[102][MAX];
int sz;
int getPath() {
	queue<pii> q;
	q.push(mp(src,1e6));
	memset(par, -1, sizeof par);
	memset(vis, 0, sizeof vis);
	vis[src] = 1;
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (cur.first == dest)
			return cur.second;

		fo(i,adjlist[cur.first].size()) {
			pii nxt = adjlist[cur.first][i];
			if (vis[nxt.first] || nxt.second < 1)
				continue;
			vis[nxt.first] = 1;
			par[nxt.first] = cur.first;
			q.push(mp(nxt.first, min(cur.second, nxt.second)));
		}
	}
	return -1;

}

void edit(int src, int dest, int flow) {

	fo(i,adjlist[src].size())
		if (adjlist[src][i].first == dest)
			adjlist[src][i].second -= flow;
	bool f = 0;
	fo(i,adjlist[dest].size())
		if (adjlist[dest][i].first == src)
			adjlist[dest][i].second += flow, f = 1;

	if (!f)
		adjlist[dest].push_back(mp(src,flow));

}
void removePath(int r) {
	int d = dest;
	int e = 1;
	while (par[d] != -1) {
		paths[sz][e++] = d;
		edit(par[d], d, r);
		d = par[d];
	}
	paths[sz][e++] = src;
	paths[sz++][0] = e;
}

int maxFlow() {

	int totalFlow = 0, val = 0;
	while ((val = getPath()) != -1) {
		totalFlow += val;
		removePath(val);
		if (sz == k)
			return totalFlow;
	}
	return totalFlow;
}
int main() {

	int t, tst = 1;
	string str;
	while (scanf("%d%d", &k, &n) != -1) {
		if (k == 0 && n == 0)
			break;
		sz = 0;

		if (n == 2) {
			while (k--)
				printf("1 2\n");
			printf("\n");
			scanf("%d%d", &n, &k);
			continue;
		}

		fo(i,MAX)
			adjlist[i].clear();
		memset(paths, 0, sizeof paths);

		getline(cin, str);
		foe(i,1,n) {
			if (i > 2)
				adjlist[i].push_back(mp(i+n,1));
			getline(cin, str);
			stringstream s(str);
			while (s >> t) {
				if (i > 2)
					adjlist[i + n].push_back(mp(t,1));
				else
					adjlist[i].push_back(mp(t,1));
			}
		}

		printf("Case %d:\n", tst++);
		n += n;
		int res = maxFlow();
		if (res < k) {
			printf("Impossible\n\n");
			continue;
		}

		fo(i,k) {
			for (int j = paths[i][0] - 1; j > 0; j--) {
				if (paths[i][j] > n / 2)
					continue;

					printf("%d ", paths[i][j]);
			}
			printf("\n");
		}

		printf("\n");
	}

	return 0;
}

