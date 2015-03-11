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
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef stringstream sstr;

map<string, int> memo;
int DP(int c, string line) {
	if (memo.find(line) != memo.end())
		return memo[line];

	int res = 13;
	foo(i,1,12) {
		if (line[i] == 'o' && i < 11) {
			if (line[i + 1] == 'o' && line[i - 1] == '-') {
				line[i] = line[i + 1] = '-', line[i - 1] = 'o';
				res = min(res, DP(c - 1, line));
				line[i] = line[i + 1] = 'o', line[i - 1] = '-';
			}

			else if (line[i + 1] == '-' && line[i - 1] == 'o') {
				line[i] = line[i - 1] = '-', line[i + 1] = 'o';
				res = min(res, DP(c - 1, line));
				line[i] = line[i - 1] = 'o', line[i + 1] = '-';
			}
		}

	}

	if (res == 13)
		return memo[line] = c;
	return memo[line] = res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int tst;
	string line;
	scanf("%d", &tst);

	while (tst--) {
		cin >> line;
		memo.clear();
		int c = count(line.begin(), line.end(), 'o');
		cout << DP(c, line) << endl;
	}
	return 0;
}
