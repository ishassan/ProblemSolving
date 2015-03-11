/*
 * E-Mail : khaled.samy@fci-cu.edu.eg
 * TopCoder Handle : Khaled91
 * Another buggy code by Khaled Samy;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)					(int)v.size()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n) 		        for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 1e9;
const double PI = 2 * acos(0);
const double EPS = 1e-9;

int DI[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int DJ[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
const int MAX = 31 * 31;

struct edge {
	int from, to, cost;
	edge(int x, int y, int z) {
		from = x, to = y, cost = z;
	}
};
int dest[MAX];
vector<edge> edges;
int n, nrow, ncol;

bool vis[MAX][MAX];
bool stones[MAX][MAX];
bool holes[MAX][MAX];
int holcost[MAX][MAX];
pair<int, int> ft[MAX][MAX];
#define clc(i,j) ((i)*(ncol)+(j))
bool bellman(int src) {
	fill(dest, dest + n, OO);
	dest[src] = 0;
	for (int i = 0; i < n; i++) {
		bool relax = false;
		for (int j = 0; j < SZ(edges); j++) {
			if (dest[edges[j].to] > dest[edges[j].from] + edges[j].cost) {
				relax = true;
				dest[edges[j].to] = dest[edges[j].from] + edges[j].cost;
			}
		}
		if (!relax)
			break;
		if (i == n - 1)
			return false;
	}
	return true;
}
int valid(int i, int j) {
	if (i < 0 || i >= nrow || j < 0 || j >= ncol)
		return false;
	return true;
}

void ff(int i, int j) {
	if (i == nrow - 1 && j == ncol - 1)
		return;

	if (holes[i][j]) {
		int ni = ft[i][j].first;
		int nj = ft[i][j].second;
		if (!vis[ni][nj]) {
			vis[ni][nj] = 1;
			ff(ni, nj);
		}
	} else {
		loop(k,4) {
			int ni = i + DI[k];
			int nj = j + DJ[k];
			if (valid(ni, nj) && !vis[ni][nj] && !stones[ni][nj]) {
				vis[ni][nj] = 1;
				ff(ni, nj);
			}
		}
	}
}
int main() {
	while (cin >> ncol >> nrow) {
		if (!nrow && !ncol)
			return 0;

		n = nrow * ncol;
		CLR(stones,0);
		CLR(holes,0);
		CLR(vis,0);
		edges.clear();

		int nstone, nholes;
		cin >> nstone;
		loop(i,nstone) {
			int x, y;
			cin >> y >> x;
			stones[x][y] = 1;
		}
		cin >> nholes;
		loop(i,nholes) {
			int x, y;
			cin >> y >> x;
			holes[x][y] = 1;
			cin >> ft[x][y].second >> ft[x][y].first >> holcost[x][y];
		}
		vis[0][0] = 1;
		ff(0, 0);

		loop(i,nrow)
			loop(j,ncol)
				if (vis[i][j] && !stones[i][j] && !(i == nrow - 1 && j == ncol
						- 1)) {
					if (holes[i][j]) {
						edges.PB(edge(clc(i,j),
								clc(ft[i][j].first,ft[i][j].second),
								holcost[i][j]));
					} else {
						loop(k,4) {
							int ni = i + DI[k];
							int nj = j + DJ[k];
							if (valid(ni, nj) && !stones[ni][nj])
								edges.PB(edge(clc(i,j), clc(ni,nj), 1));
						}
					}
				}

		if (!bellman(clc(0,0)))
			cout << "Never\n";
		else if (dest[clc(nrow-1,ncol-1)] == OO)
			cout << "Impossible\n";
		else
			cout << dest[clc(nrow-1,ncol-1)] << endl;

	}
	return 0;
}
