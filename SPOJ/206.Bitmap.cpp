//SPOJ Bitmap
//BFS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int main() {

	int tst, n, m;

	cin >> tst;
	while (tst--) {

		cin >> n >> m;

		string graph[182];
		bool vis[182][182]={0};
		int res[182][182]={0};

		for (int i = 0; i < n; i++) {
			cin >> graph[i];
		}

		//BFS
		queue<pair<int, int> > q;

		//search for 1's
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (graph[i][j] == '1'){
					q.push(make_pair(i, j));
					vis[i][j]=1;
				}
			}
		}

		int steps = 0;

		int curR, curC, newR, newC;
		while (!q.empty()) {

			int size = q.size();

			while (size--) {
				curR = q.front().first;
				curC = q.front().second;

				q.pop();

				res[curR][curC] = steps;

				for (int i = 0; i < 4; i++) {
					newR = curR + dr[i];
					newC = curC + dc[i];

					if (newR < 0 || newR >= n || newC < 0 || newC >= m)
						continue;

					if (graph[newR][newC] == '0' && vis[newR][newC] == 0){
						q.push(make_pair(newR, newC));
						vis[newR][newC]=1;
					}
				}
			}

			steps++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << res[i][j];

				if(j+1<m)
					cout<<" ";

				else
					cout<<endl;
			}
		}
	}

	return 0;
}
