#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

const int MAX = 100;
const int OO = 1000000;
int graph[MAX][MAX];

const int dirr[4] = { 1, -1, 0, 0 };
const int dirc[4] = { 0, 0, 1, -1 };

int r, c;

int Dijkstra(int graph[MAX][MAX], int desti, int destj) {
	int dest[MAX][MAX];
	bool vis[MAX][MAX];
	fo(i,r)
		fo(j,c)
			dest[i][j] = OO, vis[i][j] = 0;

	dest[0][0] = graph[0][0];
	int n = r * c;
	fo(t,n) {
		int val = OO, besti = -1, bestj = -1;
		fo(i,r) {
			fo(j,c) {
				if (!vis[i][j] && dest[i][j] < val)
					val = dest[i][j], besti = i, bestj = j;
			}

		}

		vis[besti][bestj]=1;

		fo(k,4) {
			int nxtr = besti + dirr[k];
			int nxtc = bestj + dirc[k];

			if (nxtr < 0 || nxtc < 0 || nxtr == r || nxtc == c)
				continue;


			if (dest[nxtr][nxtc] > (val = dest[besti][bestj] + graph[nxtr][nxtc]))
				dest[nxtr][nxtc] = val;
		}

	}

	return dest[desti][destj];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif

	int tst;
	cin >> tst;
	while (tst--) {
		cin >> r >> c;

		fo(i,r)
			fo(j,c)
				cin >> graph[i][j];

		int desti, destj, TL;
		cin >> desti >> destj >> TL;

		int shortest = Dijkstra(graph, desti - 1, destj - 1);

		if (shortest > TL)
			cout << "NO\n";
		else
			cout << "YES\n" << TL - shortest << endl;
	}
	return 0;
}
