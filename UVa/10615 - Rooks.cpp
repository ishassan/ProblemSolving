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

const int MAX = 110;
char graph[MAX][MAX];
int Colors[MAX][MAX];
int col[MAX], row[MAX];
int n, mx;

struct state {
	int cmn, row, col;
};

state extract(int r, int c) {
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);

	state ret = { -1, -1, -1 };

	fo(i,n)
		row[Colors[r][i]]++;

	fo(i,n)
		col[Colors[i][c]]++;

	foe(i,1,mx) {
		if (row[i] == 0 && col[i] == 0)
			ret.cmn = i;
		else if (row[i] == 0)
			ret.row = i;
		else if (col[i] == 0)
			ret.col = i;
	}

	return ret;
}

void put(int r, int c, int rclr, int cclr) {
	Colors[r][c] = rclr;
	graph[r][c] = '.';
	fo(i,n)
		if (i != r && Colors[i][c] == rclr) {
			Colors[i][c] = cclr, graph[r][c] = '.';
			fo(j,n)
				if (j != c && Colors[i][j] == cclr) {
					put(i, j, rclr, cclr);
					break;
				}
			break;
		}
}
void init() {
	memset(graph, 0, sizeof graph);
	memset(Colors, 0, sizeof Colors);
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	mx = -1;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		init();
		scanf("%d", &n);
		fo(i,n)
			scanf("%s", graph[i]);

		fo(i,n) {
			fo(j,n)
				if (graph[i][j] == '*')
					row[i]++, col[j]++;
		}

		int ir = -1, ic = -1;
		fo(i,n) {
			if (mx < row[i])
				mx = row[i], ir = i, ic = -1;

			if (mx < col[i])
				mx = col[i], ir = -1, ic = i;
		}

		printf("%d\n", mx);
		int clr = 1;
		if (ir != -1) {
			fo(i,n)
				if (graph[ir][i] == '*')
					graph[ir][i] = '.', Colors[ir][i] = clr++;

		}

		else if (ic != -1) {
			fo(i,n)
				if (graph[i][ic] == '*')
					graph[i][ic] = '.', Colors[i][ic] = clr++;

		}

		fo(i,n)
			fo(j,n)
				if (graph[i][j] == '*') {
					graph[i][j] = '.';
					state cur = extract(i, j);

					if (cur.cmn != -1)
						Colors[i][j] = cur.cmn;

					else
						put(i, j, cur.row, cur.col);

				}
		fo(i,n)
			fo(j,n) {
				if (j + 1 < n)
					printf("%d ", Colors[i][j]);
				else
					printf("%d\n", Colors[i][j]);
			}

		//		int mtkrr[MAX];
		//		fo(j,n) {
		//			memset(mtkrr, 0, sizeof mtkrr);
		//			fo(i,n) {
		//
		//				mtkrr[Colors[i][j]]++;
		//			}
		//
		//			int* m = max_element(mtkrr+1,mtkrr+mx);
		//			if(*m>1)
		//				cout<<*m;
		//		}

	}
	return 0;
}
