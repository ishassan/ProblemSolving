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

char arr[200][200];
// .**
// *I*
// **.

int di[6] = { 1, 1, 0, 0, -1, -1 };
int dj[6] = { -1, 0, 1, -1, 0, 1 };

int row, col;

void DFS(int i, int j, char c) {
	if (arr[i][j] == 'B')
		return;
	arr[i][j] = c;
	char nc;
	if (c == '(')
		nc = ')';
	else if (c == ')')
		nc = '(';
	rep(k,6) {
		int newi = i + di[k];
		int newj = j + dj[k];
		if (newi < 0 || newi >= row || newj < 0 || newj >= col)
			continue;
		char& newc = arr[newi][newj];
		if (newc == '.')
			continue;
		else if (c == '(' || c == ')') {
			if (newc == '*')
				DFS(newi, newj, nc);

			else if(newc == 'B')
				arr[i][j] = c = 'B';

			else if (newc == '(' || newc == ')')
				if (newc != nc)
					DFS(newi, newj, 'B');
		}
		else if (c == 'B' && newc != 'B')
			DFS(newi, newj, 'B');

	}

}
int main() {

	while (scanf("%d%d", &row, &col) && (row || col)) {
		mem(arr,'.');
		vector<pii> start;
		rep(i,row)
			rep(j,col) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] == 'I')
					start.push_back(mp(i,j));
			}
		rep(i,sz(start))
			DFS(start[i].first, start[i].second, '(');
		printf("\n");
		rep(i,row) {
			rep(j,col) {
				if (arr[i][j] == '*')
					arr[i][j] = 'F';
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
