#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
typedef long long ll;

using namespace std;

pair<int, int> points[12];
bool vis[12];
int n;

int DFS(int node) {

	int mn = 1 << 27;

	for (int i = 1; i < n; i++) {
		if (vis[i])
			continue;
		vis[i] = 1;
		int dist = abs(points[node].first - points[i].first) + abs(
				points[node].second - points[i].second);
		mn = min(mn, DFS(i) + dist);
		vis[i] = 0;
	}
	if (mn == 1 << 27) {
		return abs(points[node].first - points[0].first) + abs(
			points[node].second - points[0].second);
	}
	return mn;
}
int main() {

	int tst;
	cin >> tst;
	while (tst--) {
		memset(vis,0,sizeof vis);
		memset(points,0,sizeof points);
		int szx, szy, stx, sty;
		cin >> szx >> szy >> stx >> sty >> n;
		points[0] = make_pair(stx, sty);
		n++;
		for (int i = 1; i < n; ++i) {
			cin >> points[i].first >> points[i].second;
		}

		int res = DFS(0);
		printf("The shortest path has length %d\n",res);
	}

	return 0;
}
