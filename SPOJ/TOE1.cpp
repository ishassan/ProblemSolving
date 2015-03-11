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
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

char grid[5][5];
bool vis[262154];
vector<pair<pib, bool> > q; //((state,turn),win)

int encode() {
	int res = 0;
	rep(i,3)
		rep(j,3) {
			res <<= 2;
			if (grid[i][j] == 'X')
				res |= 1;
			else if (grid[i][j] == 'O')
				res |= 2;
		}
	return res;
}

void decode(int n) {
	for (int i = 2; i >= 0; --i) {
		for (int j = 2; j >= 0; --j) {
			if ((n & 3) == 0)
				grid[i][j] = '.';
			else if ((n & 3) == 1)
				grid[i][j] = 'X';
			else if ((n & 3) == 2)
				grid[i][j] = 'O';
			n >>= 2;
		}
	}
}

bool final(int i, int j) {
	if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
		return 1;
	if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j])
		return 1;

	char c = grid[i][j];
	bool eq = 1;
	int cnt = 1;
	for (int k = 1; k < 3; ++k) {
		if (j + k < 3 && i + k < 3) {
			if (grid[i + k][j + k] != c)
				eq = 0;
			else
				++cnt;
		}
		if (i - k >= 0 && j - k >= 0) {
			if (grid[i - k][j - k] != c)
				eq = 0;
			else
				++cnt;
		}

	}
	if (eq && cnt == 3)
		return 1;

	eq = 1, cnt = 1;
	for (int k = 1; k < 3; ++k) {
		if (i - k >= 0 && j + k < 3) {
			if (grid[i - k][j + k] != c)
				eq = 0;
			else
				++cnt;
		}
		if (i + k < 3 && j - k >= 0) {
			if (grid[i + k][j - k] != c)
				eq = 0;
			else
				++cnt;
		}
	}
	return (eq && cnt == 3);
}
// 1:x , 0:o
void BFS(int st) {
	q.push_back(mp(mp(st,1),0));
	vis[st] = 1;
	for (int idx = 0; idx < sz(q); ++idx) {
		if (q[idx].second)
			continue;

		decode(q[idx].first.first);

		rep(i,3)
			rep(j,3) {
				if (grid[i][j] != '.')
					continue;
				if (q[idx].first.second == 1)
					grid[i][j] = 'X';
				else
					grid[i][j] = 'O';

				int nw = encode();
				if(vis[nw]){
					grid[i][j] = '.';
					continue;
				}
				q.push_back(mp(mp(nw, !q[idx].first.second), final(i,j)));
				vis[nw] = 1;
				grid[i][j] = '.';

			}
	}
}
int main() {
	mem(grid,'.');
	BFS(encode());
	int tst;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%s%s%s", grid[0], grid[1], grid[2]);
		int st = encode();
		printf(vis[st] ? "yes\n" : "no\n");
	}

	return 0;
}
