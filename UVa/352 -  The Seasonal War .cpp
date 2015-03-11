#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>
#include <cmath>
#include <queue>
#include <set>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int di[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dj[] = { 0, 1, -1, 1, -1, 0, 1, -1 };

int in;
char grid[26][26];

void BFS(int srci, int srcj) {
	queue<pair<int, int> > q;
	q.push(mp(srci,srcj));
	bool b = 0;
	while (!q.empty()) {
		srci = q.front().first;
		srcj = q.front().second;
		q.pop();

		fo(d,8) {
			int newr = srci + di[d];
			int newc = srcj + dj[d];

			if (newr < 0 || newc < 0 || newr >= in || newc >= in)
				continue;

			if (grid[newr][newc] == '0')
				continue;

			grid[newr][newc] = '0';
			q.push(mp(newr,newc));
		}
	}
}
int main() {

	int tst = 1;

	while (cin >> in) {
		fo(i,in)
			cin >> grid[i];

		int res = 0;
		fo(i,in)
			fo(j,in) {
				if (grid[i][j] != '1')
					continue;

				BFS(i, j);
				res++;
			}
		cout << "Image number " << tst++ << " contains " << res
				<< " war eagles.\n";
	}
	return 0;
}
