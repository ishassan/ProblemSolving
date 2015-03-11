#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

string str;

int memo[1002][1002];
string memo2[1002][1002];

void clr() {
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++)
			memo2[i][j] = "";
}
int DP(int s, int e) {
	if (s > e)
		return 0;

	if (s == e)
		return 1;

	int& m = memo[s][e];

	if (m != -1)
		return m;

	int maxi = -2;
	if (str[s] == str[e])
		maxi = max(maxi, DP(s + 1, e - 1) + 2);

	maxi = max(maxi, DP(s, e - 1));
	maxi = max(maxi, DP(s + 1, e));

	return m = maxi;
}

string build(int s, int e) {
	if (s > e)
		return "";

	if (s == e) {
		string tmp;
		tmp += str[s];
		return tmp;
	}

	if (memo2[s][e] != "")
		return memo2[s][e];

	vector<string> v;
	int ans = DP(s, e);
	string tmp;
	if (ans == DP(s + 1, e - 1) + 2 && str[s] == str[e]) {
		tmp = str[s] + build(s + 1, e - 1) + str[e];
		v.push_back(tmp);
	}
	if (ans == DP(s + 1, e)) {
		tmp = build(s + 1, e);
		v.push_back(tmp);
	}

	if (ans == DP(s, e - 1)) {
		tmp = build(s, e - 1);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	return memo2[s][e] = v[0];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	while (cin >> str) {
		memset(memo, -1, sizeof memo);
		clr();
		int n = str.size() - 1;
		cout << build(0, n) << endl;

	}

	return 0;
}
