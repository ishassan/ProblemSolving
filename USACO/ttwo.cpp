/*
 ID: fci_isl1
 LANG: C++
 TASK: ttwo
 */

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
#include <queue>
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef stringstream sstr;

string graph[10];

struct state {
	int i, j;
	char dir;
};

char visf[10][10], visc[10][10];

void next(state& st) {
	if (st.dir == 'N') {
		if (st.i > 0 && graph[st.i - 1][st.j] != '*')
			--st.i;
		else
			st.dir = 'E';
	}

	else if (st.dir == 'E') {
		if (st.j < 9 && graph[st.i][st.j + 1] != '*')
			++st.j;
		else
			st.dir = 'S';
	}

	else if (st.dir == 'S') {
		if (st.i < 9 && graph[st.i + 1][st.j] != '*')
			++st.i;
		else
			st.dir = 'W';
	}

	else if (st.dir == 'W') {
		if (st.j > 0 && graph[st.i][st.j - 1] != '*')
			--st.j;
		else
			st.dir = 'N';
	}

}
int BFS() {
	state f, c;
	queue<state> q;
	fo(i,10)
		fo(j,10)
			if (graph[i][j] == 'F')
				f.i = i, f.j = j, f.dir = 'N';

	q.push(f);
	fo(i,10)
		fo(j,10)
			if (graph[i][j] == 'C')
				c.i = i, c.j = j, c.dir = 'N';
	q.push(c);
	int res = 0;
	while (!q.empty()) {
		f = q.front();
		q.pop();
		c = q.front();
		q.pop();

		if (f.i == c.i && f.j == c.j)
			return res;

		if (visf[f.i][f.j] == f.dir && visc[c.i][c.j] == c.dir)
			return 0;

		visf[f.i][f.j] = f.dir, visc[c.i][c.j] = c.dir;

		next(f);
		q.push(f);
		next(c);
		q.push(c);

		res++;

	}

	return -1;

}

int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);

	fo(i,10)
		cin >> graph[i];

	cout << BFS() << endl;

	return 0;
}
