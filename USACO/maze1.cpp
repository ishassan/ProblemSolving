/*
 ID: fci_isl1
 LANG: C++
 TASK: maze1
 */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

string graph[205];

int dr1[4] = { 0, 0, -1, 1 };
int dc1[4] = { 1, -1, 0, 0 };

int dr2[4] = { 0, 0, -2, 2 };
int dc2[4] = { 2, -2, 0, 0 };

int h, w;
int r1, c1, r2, c2;

bool vis[205][80];

struct state {
	int r, c, step;
};

void mem();

int BFS() {

	state st,cp;
	queue<state> q;
	st.r = r1 , st.c = c1, st.step=1;
	q.push(st);
	st.r = r2 , st.c = c2, st.step=1;
	q.push(st);

	while(!q.empty()){
		st = q.front();
		q.pop();
		cp = st;

		for (int d = 0; d < 4; ++d) {
			int newr1 = st.r + dr1[d];
			int newc1 = st.c + dc1[d];
			int newr2 = st.r + dr2[d];
			int newc2 = st.c + dc2[d];

			if(newr2<0 || newc2<0 || newr2>=h ||newc2>=w)
				continue;

			if(vis[newr2][newc2])
				continue;

			if(graph[newr1][newc1]==' ' && graph[newr2][newc2]==' '){
				vis[newr2][newc2] = 1;
				st.r = newr2 , st.c = newc2 ,st.step++;
				q.push(st);
				st = cp;
			}

		}
	}

	return st.step;
}

int main() {
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);

	cin >> w >> h;
	w = 2 * w + 1, h = 2 * h + 1;
	getline(cin, graph[0]);

	for (int i = 0; i < h; ++i)
		getline(cin, graph[i]);

	bool found1 = 0, found2 = 0;
	//check first and last row
	for (int i = 0; i < w; ++i) {
		if (graph[0][i] == ' ') {
			if (found1)
				r2 = 0, c2 = i, found2 = 1;
			else
				r1 = 0, c1 = i, found1 = 1;
		}

		if (graph[h - 1][i] == ' ') {
			if (found1)
				r2 = h - 1, c2 = i, found2 = 1;
			else
				r1 = h - 1, c1 = i, found1 = 1;
		}
	}

	//check first and last column
	if (found1 == 0 || found2 == 0)
		for (int i = 0; i < h; ++i) {
			if (graph[i][0] == ' ') {
				if (found1)
					r2 = i, c2 = 0, found2 = 1;
				else
					r1 = i, c1 = 0, found1 = 1;
			}
			if (graph[i][w - 1] == ' ') {
				if (found1)
					r2 = i, c2 = w - 1, found2 = 1;
				else
					r1 = i, c1 = w - 1, found1 = 1;
			}
		}

	//search for exit1
	for (int d = 0; d < 4; ++d) {
		int newr = r1 + dr1[d];
		int newc = c1 + dc1[d];

		if (newr < 0 || newc < 0 || newr >= h || newc >= w)
			continue;

		if (graph[newr][newc] == ' ') {
			r1 = newr, c1 = newc;
			break;
		}
	}

	//search for exit2
	for (int d = 0; d < 4; ++d) {
		int newr = r2 + dr1[d];
		int newc = c2 + dc1[d];

		if (newr < 0 || newc < 0 || newr >= h || newc >= w)
			continue;

		if (graph[newr][newc] == ' ') {
			r2 = newr, c2 = newc;
			break;
		}
	}

	mem();
	cout<<BFS()<<endl;
	return 0;
}

void mem() {
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			vis[i][j] = 0;
}
