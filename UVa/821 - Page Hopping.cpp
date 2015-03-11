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

using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

const int MAX = 102;
int adjMax[MAX][MAX];
const int OO = 1000000;

void floydWarshal(vi& nodes,int n) { // O(n^3)
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;

				int a = nodes[i], b=nodes[j],c=nodes[k];

				if (adjMax[a][b] > (adjMax[a][c] + adjMax[c][b]))
					adjMax[a][b] = adjMax[a][c] + adjMax[c][b];
			}
		}
	}
}

bool find(vi& v, int n) {
	int sz = v.size();
	fo(i,sz) {
		if (v[i] == n)
			return 1;

	}
	return 0;
}

int sum() {
	int res = 0;
	fo(i,MAX)
		fo(j,MAX)
			if (adjMax[i][j] != OO)
				res += adjMax[i][j];
	return res;
}

void init() {
	fo(i,MAX)
		fo(j,MAX)
			adjMax[i][j] = OO;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int c=1;
	int src, dis;
	bool zero = 0;
	vi nodes;
	init();
	while (cin >> src >> dis) {

		if (src == 0 && dis == 0) {
			if (zero)
				return 0;

			zero = 1;
			int sz = nodes.size();
			floydWarshal(nodes,sz);
			float res = (float) sum() / (sz * (sz - 1));
			printf("Case %d: average length between pages = %0.3f clicks\n",c++, res);

			nodes.clear();

			init();
			continue;
		}
		zero = 0;
		adjMax[src][dis] = 1;
		if (!find(nodes, src))
			nodes.push_back(src);
	}

	return 0;
}
