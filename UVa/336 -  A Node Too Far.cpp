#include<iostream>
#include<map>
#include<vector>
#include<memory.h>
#include<stdlib.h>
#include<stdio.h>
#include<queue>
using namespace std;
map<int, int> m;
int cnt = 0;
int get(int node) {
	if (m.count(node))
		return m[node];
	m[node] = cnt++;
	return m[node];
}
vector<vector<int> > adj;
int vis[100];
int bfs(int node, int TTL) {
	memset(vis, 0, sizeof vis);
	queue<int> q;
	int ret = 1;
	q.push(node);
	vis[node] = 1;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			if (TTL == 0)
				return ret;
			int tmp = q.front();
			q.pop();
			for (int i = 0; i < (int) adj[tmp].size(); i++) {
				if (!vis[adj[tmp][i]]) {
					vis[adj[tmp][i]] = 1;
					q.push(adj[tmp][i]);
					ret++;
				}
			}
		}
		TTL--;
	}
	return ret;
}
int main() {
	//freopen("a.txt","rt",stdin);
	//freopen("b.txt","wt",stdout);
	int n;
	int t = 1;
	while (cin >> n && n) {
		adj.clear();
		adj.resize(100);
		m.clear();
		cnt = 0;
		while (n--) {
			int s, d;
			cin >> s >> d;
			adj[get(s)].push_back(get(d));
			adj[get(d)].push_back(get(s));
		}
		int node, TTL;
		while (cin >> node >> TTL && (node || TTL)) {
			int ret = bfs(get(node), TTL);
			if(!m.count(node))
				ret = 0;
			printf(
					"Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
					t++, cnt - ret, node, TTL);
		}
	}

	return 0;
}
