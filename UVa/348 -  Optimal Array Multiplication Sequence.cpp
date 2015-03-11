#include <cstring>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> mat[11];
int memo[11][11];

int DP(int s, int e) {
	if (s == e)
		return 0;

	if (s == e - 1)
		return mat[s].first * mat[s].second * mat[e].second;

	int &m = memo[s][e];
	if (m != -1)
		return m;

	int best = 1 << 27, val;
	for (int i = s; i < e; ++i) {
		val = DP(s, i) + DP(i + 1, e);
		val += (mat[s].first * mat[i].second * mat[e].second);

		if (val < best)
			best = val;
	}

	return m = best;
}

string str[10] = { "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10" };
string build(int s, int e) {
	if (s == e)
		return str[s];

	if (s == e - 1)
		return "(" + str[s] + " x " + str[e] + ")";

	int ans = DP(s, e);
	int val;
	for (int i = s; i < e; ++i) {
		val = DP(s, i) + DP(i + 1, e);
		val += (mat[s].first * mat[i].second * mat[e].second);

		if (ans == val) {

			return "(" + build(s, i) + " x " + build(i + 1, e) + ")";
		}
	}

	return "";

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tst = 1;
	int n;
	while (scanf("%d", &n) && n > 0) {
		int r, c;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &r, &c);
			mat[i] = make_pair(r, c);
		}
		memset(memo, -1, sizeof memo);
		cout<<"Case "<<tst++<<": ";
		cout << build(0, n - 1) << endl;

	}

	return 0;

}
