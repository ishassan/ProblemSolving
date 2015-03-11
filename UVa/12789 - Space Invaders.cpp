#include <bits/stdc++.h>
#define sz(v) (int)((v).size())
using namespace std;

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

const int SIZE = 1000010;

struct DisjointSets {
	int parent[SIZE], rank[SIZE], componentsCnt;
	DisjointSets(int n = 0) {
		memset(rank, 0, n*(sizeof rank[0]));
		for (int i = 0; i < n; i++)
			parent[i] = i;
		componentsCnt = n;
	}
	int find(int e) {
		return parent[e] == e ? e : parent[e] = find(parent[e]);
	}
	bool join(int e1, int e2) {
		int p1 = find(e1), p2 = find(e2);
		if (p1 == p2)
			return 0;
		if (rank[p1] == rank[p2])
			rank[p1]++;
		if (rank[p2] > rank[p1])
			swap(p1, p2);
		parent[p2] = p1;
		componentsCnt--; // new components get merged
		return 1;
	}
} dis;

int n, m, s;
int src, dest;
string g[1003];

inline int getnode(int i, int j) {
	return i * m + j;
}

void connect4(int i, int j) {
	if (g[i][j] == '#')
		return;
	for (int d = 0; d < 4; ++d) {
		int ni = i + di[d];
		int nj = j + dj[d];
		if(ni == -1){
			dis.join(getnode(i,j), src);
			continue;
		}
		if(ni == n){
			dis.join(getnode(i,j), dest);
			continue;
		}
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || g[ni][nj] == '#')
			continue;
		dis.join(getnode(i, j), getnode(ni, nj));
	}
}
pair<int, bool> plays[10005];
int hashes[1004][10015];
int idxfront[1004],idxback[1004];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	while (cin >> n >> m >> s) {
		memset(idxfront,0,m*(sizeof (idxfront[0])));
		memset(idxback,0,m*(sizeof (idxback[0])));

		dis = DisjointSets(n * m + 2);
		src = n * m;
		dest = n * m + 1;
		for (int i = 0; i < n; ++i) {
			cin >> g[i];
		}
		for (int i = 0; i < s; ++i) {
			cin >> plays[i].first;
			plays[i].second = plays[i].first > 0 ? 0 : 1;
			plays[i].first = abs(plays[i].first) - 1;
		}
		for (int j = 0; j < m; ++j) {
			if (g[0][j] == '.')
				dis.join(src, getnode(0, j));

		}
		for (int j = 0; j < m; ++j) {
			if (g[n - 1][j] == '.')
				dis.join(dest, getnode(n - 1, j));
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				connect4(i, j);
			}
		}
		if (dis.find(src) == dis.find(dest)) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == '#')
					hashes[j][idxback[j]++] = i;//push back
			}
		}
		int idx = -1;
		for (int i = 0; i < s; ++i) {
			int curcol = plays[i].first;
			int currow;
			if (plays[i].second == 0) {
				currow = hashes[curcol][idxfront[curcol]]; //front
				idxfront[curcol]++; //pop front
			} else {
				currow = hashes[curcol][idxback[curcol]-1]; // back
				idxback[curcol]--;
			}
			g[currow][curcol] = '.';
			connect4(currow, curcol);
			if (dis.find(src) == dis.find(dest)) {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			cout << "X\n";
			continue;
		}
		cout << (plays[idx].second ? -(idx + 1) : (idx + 1)) << "\n";
	}

}
