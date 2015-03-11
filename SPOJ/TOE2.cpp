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
bool win[262154];

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
	bool end = 1;
	rep(k,3)
		rep(j,3)
			if (grid[k][j] == '.')
				end = 0;
	if (end)
		return 1;

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
	queue<pib> q;
	q.push(mp(st,1));
	vis[st] = 1;
	while (q.size()) {
		st = q.front().first;
		int turn = q.front().second;
		q.pop();

		decode(st);

		rep(i,3)
			rep(j,3) {
				if (grid[i][j] != '.')
					continue;
				if (turn == 1)
					grid[i][j] = 'X';
				else
					grid[i][j] = 'O';

				int nw = encode();
				if (vis[nw]) {
					grid[i][j] = '.';
					continue;
				}
				if (final(i, j)) {
					win[nw] = vis[nw] = 1;
					grid[i][j] = '.';
					continue;
				}
				q.push(mp(nw, !turn));
				vis[nw] = 1;
				grid[i][j] = '.';
			}
	}
}
int main() {
	mem(grid,'.');
	BFS(encode());
	char str[20];
	while (scanf("%s", str) && strcmp(str, "end")) {
		rep(i,3)
			rep(j,3)
				grid[i][j] = str[i * 3 + j];

		int st = encode();
		printf(win[st] ? "valid\n" : "invalid\n");
	}

	return 0;
}
