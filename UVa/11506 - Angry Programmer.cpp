#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include <map>
using namespace std;
const int OO = 100000000;
const int OO2 = 1000000;
const int MAX = 300;
int adjMax[MAX][MAX], prev[MAX], size;

int Dijkstra_maxmini(int src, int end) {

	memset(prev, -1, sizeof(prev));
	vector<int> dist(size, 0);
	vector<int> vis(size, 0);

	dist[src] = OO;
	for (int k = 1; k < size; k++) {

		int maxi = 0, nxt = -1;
		for (int i = 1; i < size; i++)
			if (!vis[i] && dist[i] > maxi)
				nxt = i, maxi = dist[i];

		if (nxt == end)
			return dist[end];
		if (nxt == -1)
			return -1;

		vis[nxt] = 1;
		for (int i = 1; i < size; i++) {
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
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int m, w, n, c= 0;

	while (cin >> m >> w) {

		if (m == 0 && w == 0)
			break;
		size = m + m + 1;

		for (int i = 1; i < size; ++i) {
			for (int j = 1; j < size; ++j) {
				adjMax[i][j] = 0; // no path
			}
		}

		for (int i = 1; i <= (m - 2); i++) {
			cin >> n >> c;
			adjMax[n][n + m] = c;
			adjMax[n + m][n] = c;
		}
		adjMax[1][1 + m] = OO2;
		adjMax[m][m + m] = OO2;

		for (int t = 1; t <= w; t++) {
			int f, t, cost;
			cin >> f >> t >> cost;

			adjMax[f + m][t] = cost;
			adjMax[t+m][f] = cost;

		}

		cout << maxFlow(1, m+m) << endl;
	}

	return 0;
}
