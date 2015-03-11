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

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int h, w;
char graph[102][102];
bool vis[102][102][4];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

struct state {
	int i, j, turns, dir;
};

int BFS(int i1, int j1, int i2, int j2) {
	deque<state> q;
	rep(d,4) {
		state s = { i1, j1, 0, d };
		q.push_back(s);
	}

	state s;
	while (q.size()) {
		s = q.front();
		q.pop_front();

		if (s.i == i2 && s.j == j2)
			return s.turns;
		vis[s.i][s.j][s.dir] = 1;
		rep(d,4) {
			int newi = s.i + di[d];
			int newj = s.j + dj[d];
			if (newi < 0 || newi >= h || newj < 0 || newj >= w || (s.dir + 2)
					% 4 == d)
				continue;
			if (vis[newi][newj][d] || graph[newi][newj] == '*')
				continue;

			state ns = { newi, newj, s.turns, d };
			if (d != s.dir) {
				ns.turns++;
				q.push_back(ns);
			} else
				q.push_front(ns);
		}

	}
}

int main() {
	int i1 = -1, j1, i2, j2;
	scanf("%d%d", &w, &h);
	rep(i,h) {
		scanf("%s", graph[i]);
		rep(j,w)
			if (graph[i][j] == 'C')
				if (i1 == -1)
					i1 = i, j1 = j;
				else
					i2 = i, j2 = j;

	}
	printf("%d\n", BFS(i1, j1, i2, j2));

	return 0;
}
