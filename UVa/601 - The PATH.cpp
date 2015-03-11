#include<iostream>
#include<queue>
#include<memory.h>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int vis[90][89];
char g[90][90];
int n;

int DI[] = { 1, -1, 0, 0 };
int DJ[] = { 0, 0, 1, -1 };

void bfs(char home, char mark, queue<pair<int, int> > q) {
	memset(vis, 0, sizeof vis);
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		vis[cur.first][cur.second] = 1;
		g[cur.first][cur.second] = mark;
		for (int k = 0; k < 4; k++) {
			int ni = cur.first + DI[k];
			int nj = cur.second + DJ[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= n || vis[ni][nj]
					|| g[ni][nj] != home)
				continue;
			q.push(make_pair(ni, nj));
		}
	}
}
bool valid(char t1, char t2) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j] == 'U') {
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 4; l++) {
						if (l == k)
							continue;
						int ni = i + DI[k];
						int nj = j + DJ[k];
						if (ni < 0 || ni >= n || nj < 0 || nj >= n)
							continue;
						int nii = i + DI[l];
						int njj = j + DJ[l];
						if (nii < 0 || nii >= n || njj < 0 || njj >= n)
							continue;
						if (g[ni][nj] == t1 && g[nii][njj] == t2)
							return 1;
					}
				}

				if (t1 == '1') {
					if (j == n - 1 && j > 0 && g[i][j - 1] == t1)
						return 1;
				}
				if (t2 == '2') {
					if (j == 0 && j + 1 < n && g[i][j + 1] == t2)
						return 1;
				}
				if (t1 == '3') {
					if (i == n - 1 && i > 0 && g[i - 1][j] == t1)
						return 1;
				}
				if (t2 == '4') {
					if (i == 0 && i + 1 < n && g[i + 1][j] == t2)
						return 1;
				}
			}
	return 0;
}
int main() {
	// freopen("b.txt", "wt", stdout);
	while (cin >> n && n) {
		queue<pair<int, int> > white1, black1, white2, black2;
		for (int i = 0; i < n; i++) {
			cin >> g[i];
			if (g[i][0] == 'W')
				white1.push(make_pair(i, 0));
			if (g[i][n - 1] == 'W')
				white2.push(make_pair(i, n - 1));
			if (i == 0) {
				for (int j = 0; j < n; j++)
					if (g[0][j] == 'B')
						black1.push(make_pair(0, j));
			}
			if (i == n - 1) {
				for (int j = 0; j < n; j++)
					if (g[n-1][j] == 'B')
						black2.push(make_pair(n - 1, j));
			}
		}

		if (n == 1 && g[0][0] == 'U') {
			cout << "White can win in one move.\n";
			continue;
		}
		bool done = 0;

		bfs('W', '1', white1);

		for (int i = 0; i < n; i++)
			if (g[i][n - 1] == '1') {
				cout << "White has a winning path.\n";
				done = 1;
				break;
			}

		if (done)
			continue;

		bfs('B', '3', black1);

		for (int i = 0; i < n; i++)
			if (g[n - 1][i] == '3') {
				cout << "Black has a winning path.\n";
				done = 1;
				break;
			}

		if (done)
			continue;

		bfs('W', '2', white2);

		if (valid('1', '2')) {
			cout << "White can win in one move.\n";
			done = 1;
		}

		if (done)
			continue;

		bfs('B', '4', black2);

		if (valid('3', '4')) {
			cout << "Black can win in one move.\n";
			done = 1;
		}

		if (done)
			continue;

		cout << "There is no winning path.\n";

	}
	return 0;
}
