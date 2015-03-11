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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
using namespace std;

int dist[1000002];
int Left[1000002];
int Right[1000002];

/*
 * 1 3 5 7 10
 * The algorithm is as follows
 * we decide to build a post office @ 1, so the cost = 0
 * when we build a post office @ i, the cost = cost[i-1] + current cost
 * same in right array
 * left array contains 1 post office & right array contains the another
 * so in last line, we write Right[i+1], we don't care of cost between the two intervals(left & right)
 * LLLLL RRRRR
 *
 */
int main() {
	int n;
	cin >> n;
	fo(i,n)
		cin >> dist[i];

	sort(dist, dist + n);

	Left[0] = 0;
	int idx = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0)
			idx++;
		Left[i] = Left[i - 1] + (dist[i] - dist[idx]);
	}

	Right[n - 1] = 0;
	idx = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if ((n - i - 1) % 2 == 0)
			idx--;
		Right[i] = Right[i + 1] + abs(dist[i] - dist[idx]);
	}

	int mn = 1 << 27;
	for (int i = 0; i < n - 1; i++) {
		mn = min(mn, Left[i] + Right[i + 1]);
	}

	cout << mn << endl;
	return 0;
}
