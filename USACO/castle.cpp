/*
 ID: fci_isl1
 LANG: C++
 TASK: castle
 */

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define mp(a,b) make_pair(a,b)

int graph[51][51];
bool vis[51][51];
int largest = 0, number = 0;
int n, m;

void memset() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			vis[i][j] = 0;
}

void BFS(int r, int c) {
	int size = 1;
	queue<pair<int, int> > q;
	q.push(mp(r,c));
	vis[r][c] = 1;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;

		q.pop();

		//check west
		if (c - 1 > -1 && !vis[r][c - 1])
			if ((graph[r][c] & 1) == 0)
				q.push(mp(r,c-1)), size++, vis[r][c - 1] = 1;

		//check north
		if (r - 1 > -1 && !vis[r - 1][c])
			if ((graph[r][c] & 2) == 0)
				q.push(mp(r-1,c)), size++, vis[r - 1][c] = 1;

		//check east
		if (c + 1 < m && !vis[r][c + 1])
			if ((graph[r][c] & 4) == 0)
				q.push(mp(r,c+1)), size++, vis[r][c + 1] = 1;

		//check south
		if (r + 1 < n && !vis[r + 1][c])
			if ((graph[r][c] & 8) == 0)
				q.push(mp(r+1,c)), size++, vis[r + 1][c] = 1;

	}

	largest = max(size, largest);

}

int main() {
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	scanf("%d%d", &m, &n);
	int ln1, ln2, ln3;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &graph[i][j]);

	memset();
	for (int j = 0; j < m; j++)
		for (int i = n - 1; i > -1; i--)
			if (!vis[i][j])
				BFS(i, j), number++;

	ln1 = number, ln2 = ln3 = largest;
	int temp1, temp2,x,y;
	char c;

	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i > -1; i--) {


			if ((graph[i][j] & 2) && i) {
				memset();
				temp1 = graph[i][j], temp2 = graph[i - 1][j], largest=0;
				graph[i][j] = graph[i][j] & (~2);
				graph[i - 1][j] = graph[i - 1][j] & (~8);
				BFS(i,j);
				graph[i][j] = temp1;
				graph[i - 1][j] = temp2;
			}

			if (ln3 < largest)
				ln3 = largest, x = i, y = j, c = 'N';

			if ((graph[i][j] & 4) && j + 1 < m) {
				memset();
				temp1 = graph[i][j], temp2 = graph[i][j + 1], largest=0;
				graph[i][j] = graph[i][j] & (~4);
				graph[i][j + 1] = graph[i][j + 1] & (~1);
				BFS(i,j);
				graph[i][j] = temp1;
				graph[i][j + 1] = temp2;
			}

			if (ln3 < largest)
				ln3 = largest, x = i, y = j, c = 'E';

		}
	}


	printf("%d\n%d\n%d\n%d %d %c\n", ln1, ln2, ln3, x + 1, y + 1, c);
	return 0;
}
