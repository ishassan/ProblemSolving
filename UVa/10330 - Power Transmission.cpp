#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include <map>
using namespace std;
const int OO = 1000000;
const int MAX = 300;
int adjMax[MAX][MAX], prev[MAX], n;

int Dijkstra_maxmini(int src, int end) {

	memset(prev, -1, sizeof(prev));
	vector<int> dist(n, 0);
	vector<int> vis(n, 0);

	dist[src] = OO;
	for (int k = 0; k < n; k++) {

		int maxi = 0, nxt = -1;
		for (int i = 0; i < n; i++)
			if (!vis[i] && dist[i] > maxi)
				nxt = i, maxi = dist[i];

		if (nxt == end)
			return dist[end];
		if (nxt == -1)
			return -1;

		vis[nxt] = 1;
		for (int i = 0; i < n; i++) {
			int tmp = dist[i];
			tmp = dist[nxt];
			tmp = adjMax[nxt][i];

			if (dist[i] < min(dist[nxt], adjMax[nxt][i]) && adjMax[nxt][i]
					!= OO)
				dist[i] = max(dist[i], min(dist[nxt], adjMax[nxt][i])), prev[i]
						= nxt;

		}
	}
	return -1;
}

void removePath(int src, int d, int r) {
	if (d == src)
		return;
	adjMax[prev[d]][d] -= r, adjMax[d][prev[d]] += r;
	removePath(src, prev[d], r);
}

int maxFlow(int src, int des) {
	int totalFlow = 0, ret = 0;
	while ((ret = Dijkstra_maxmini(src, des)) && ret != -1) {
		totalFlow += ret;
		removePath(src, des, ret);
	}
	return totalFlow;
}

int main() {
	int reg, c;

	while (cin >> reg) {
		n = reg + reg + 2;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				adjMax[i][j] = OO; // no path
			}
		}
		vector<int> v;
		v.push_back(OO);
		for (int i = 1; i <= reg; i++) {
			cin >> c;
			adjMax[i][i + reg] = c;
			v.push_back(c);
		}
		cin >> c;
		for (int t = 0; t < c; t++) {
			int f, t, cost;
			cin >> f >> t >> cost;
			adjMax[f + reg][t] = cost;
		}
		int b, d;
		cin >> b >> d;

		while (b--) {
			cin >> c;
			adjMax[0][c] = v[c];
		}
		while (d--) {
			cin >> c;
			adjMax[c + reg][reg + reg +1] = v[c];
		}

	
		cout << maxFlow(0, reg + reg + 1) << endl;
	}

	return 0;
}
