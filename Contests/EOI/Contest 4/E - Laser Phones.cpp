#include <cstdio>
#include<assert.h>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long ll;
#define state pair<pair<int,int>,int >
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
pair<int, int> src, dist;
int c, r;
char g[101][102];
bool v[101][101][4];

bool boundry(state test) {
	int x = test.first.first;
	int y = test.first.second;
	if (x >= r || x < 0 || y >= c || y < 0)
		return 0;
	return 1;
}
bool valid(state test) {
	int x = test.first.first;
	int y = test.first.second;
	if (!boundry(test) || v[x][y][test.second] || g[x][y] == '*')
		return 0;
	return 1;
}

int bfs() {
	if (src == dist)
		return 0;

	queue<pair<pair<int, int> , int> > q;
	int lvl = 0;
	for (int i = 0; i < 4; i++) {
		q.push(make_pair(src, i));
		
	}
	while (!q.empty()) {
		int siz = sz(q);
		for (int i = 0; i < siz; i++) {
			state cur = q.front();
			q.pop();
			state tmp = cur;
			if (!valid(tmp))
				continue;
			v[tmp.first.first][tmp.first.second][tmp.second] = 1;
				
			while (true) {
				tmp.first.first  += dx[cur.second];
				tmp.first.second += dy[cur.second];
				if(!boundry(tmp)||g[tmp.first.first][tmp.first.second]=='*')break;
				if (tmp.first == dist)
					return lvl;
				for (int d = 1; d < 4; d += 2) {
					tmp.second = (cur.second + d ) % 4;
					q.push(tmp);
				}
				tmp.second = cur.second;
			}
		}
		lvl++;
	}
	return -1;
}
/*
20 6
....................
...........*******..
..........*.........
.C.......*........C.
.........*..........
**********..........
 */
int main() {
	//#ifndef ONLINE_JUDGE
	//	freopen("inp.in", "rt", stdin);
	//#endif

	int k = 0;
	cin >> c >> r;
	for (int i = 0; i < r; i++) {
		cin >> g[i];
		for (int j = 0; j < c; j++)
			if (g[i][j] == 'C' && !k)
				src.first = i, src.second = j, k = 1;
			else if (g[i][j] == 'C' && k)
				dist.first = i, dist.second = j;
	}
	cout << bfs() << endl;
	return 0;
}
