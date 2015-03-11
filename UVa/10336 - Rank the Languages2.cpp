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
#include <queue>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define pb(n)       push_back(n)
#define mp(a,b)     make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vector<bool> > vvb;

const int dirr[4] = { 0, 0, 1, -1 };
const int dirc[4] = { 1, -1, 0, 0 };
int h, w;

bool flood_fill(vs& graph, vvb& vis, int r, int c) {

	if (vis[r][c])
		return 0;

	queue<pair<int, int> > q;
	q.push(mp(r,c));

	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			r = q.front().first;
			c = q.front().second;

			q.pop();

			//Test the four directions
			fo(i,4) {
				int newr = r + dirr[i];
				int newc = c + dirc[i];

				if (newr < 0 || newc < 0 || newr >= h || newc >= w)
					continue;

				if (vis[newr][newc])
					continue;

				if (graph[newr][newc] == graph[r][c])
					q.push(mp(newr,newc)), vis[newr][newc] = 1;

			}

		}
	}

	return 1;

}

int isFound(vector<pair<char, int> >& v, char tar) {

	int sz = v.size();
	fo(i,sz) {
		if (v[i].first == tar)
			return i;
	}
	return -1;
}

void print(vector<pair<char, int> >& res, int tst) {
	int sz = res.size();

	cout << "World #" << tst << endl;
	fo(i,sz) {
		cout << res[i].first << ": " << res[i].second << endl;
	}
}

void resort(vector<pair<char, int> >& res) {

	int sz = res.size();

	fo(i,sz) {
		foo(j,i+1,sz) {
			if (res[i].second < res[j].second)
				swap(res[i], res[j]);

			else if (res[i].second == res[j].second) {
				if (res[i].first > res[j].first)
					swap(res[i], res[j]);
			}
		}
	}
}
int main() {

	//freopen("out.txt","w",stdout);
	int tst;
	cin >> tst;
	fo(t,tst) {
		cin >> h >> w;
		vs graph(h);

		fo(i,h)
			cin >> graph[i];

		vvb vis(h, vector<bool> (w, 0));

		vector<pair<char, int> > res;

		//Code Core
		fo(i,h) {
			fo(j,w) {
				if (flood_fill(graph, vis, i, j)) {
					char cur = graph[i][j];
					int ind = isFound(res, cur);
					if (ind == -1)
						res.pb(mp(cur,1));
					else
						res[ind].second++;
				}
			}
		}

		resort(res);
		print(res, t + 1);
	}
	return 0;
}
