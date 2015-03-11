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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

string src, dest;
int sz1, sz2;
int memo[22][22];


int DP(int i, int j) {
	if (i == sz1)
		return sz2 - j;
	if (j == sz2)
		return sz1 - i;

	int &m = memo[i][j];
	if (m != -1)
		return m;

	if (src[i] == dest[j])
		return m = DP(i + 1, j + 1);

	int c1 = DP(i + 1, j) + 1; //delete
	int c2 = DP(i, j + 1) + 1;
	int c3 = DP(i + 1, j + 1) + 1;

	return m = min(c1, min(c2, c3));

}

void build(int i, int j) {
	if (i == sz1 && j == sz2)
		return;

	if (i == sz1) {
		cout << "I" << dest[j];
		int idx =  j+1;
		printf("%02d", idx);
		build(i, j + 1);
		return;
	}

	else if (j == sz2) {
		cout << "D" << src[i];
		int idx = j+1;
		printf("%02d", idx);
		build(i + 1, j);
		return;
	}
	int ans = DP(i, j);
	int c1 = DP(i + 1, j) + 1;
	int c2 = DP(i, j + 1) + 1;
	int c3 = DP(i + 1, j + 1) + !(src[i] == dest[j]);

	if (ans == c1) {
		cout << "D" << src[i];
		int idx = j+1;
		printf("%02d", idx);
		build(i + 1, j);
	}

	else if (ans == c3) {
		if (src[i] != dest[j]) {
			cout << "C" << dest[j];
			int idx = j+1;
			printf("%02d", idx);
		}
		build(i + 1, j + 1);
	}

	else if (ans == c2) {
		cout << "I" << dest[j];
		int idx = j+1;
		printf("%02d", idx);
		build(i, j + 1);
	}

}

int main() {

	while (cin >> src) {
		if (src == "#")
			return 0;
		cin >> dest;

		sz1 = src.size();
		sz2 = dest.size();
		memset(memo, -1, sizeof memo);
		build(0, 0);
		printf("E\n");
	}

	return 0;
}

