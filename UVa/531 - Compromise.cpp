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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

vector<string> str1, str2;
int sz1, sz2;
int memo[3002][3002];
bool first;
int DP(int i, int j) {
	if (i == sz1 || j == sz2)
		return 0;

	int &m = memo[i][j];
	if (m != -1)
		return m;

	if (str1[i] == str2[j])
		return m = DP(i + 1, j + 1) + 1;

	int c1 = DP(i + 1, j);
	int c2 = DP(i, j + 1);

	return m = max(c1, c2);
}

void build(int i, int j) {
	if (i == sz1 || j == sz2)
		return;

	int ans = DP(i, j);
	if (str1[i] == str2[j] && ans == DP(i + 1, j + 1) + 1) {
		if (first)
			first=0, cout << str1[i];
		else
			cout << " " << str1[i];

		build(i + 1, j + 1);
	}

	if (ans == DP(i + 1, j))
		build(i + 1, j);

	else if (ans == DP(i, j + 1))
		build(i, j + 1);
}
int main() {

//	freopen("in.txt","r",stdin);

	string s;
	while (1) {
		str1.clear(), str2.clear();
		memset(memo, -1, sizeof memo);
		first = 1;
		while (cin >> s && s != "#") {
			str1.push_back(s);
		}

		while (cin >> s && s != "#") {
			str2.push_back(s);
		}

		if (cin.fail() || s != "#")
			return 0;

		sz1 = str1.size(), sz2 = str2.size();
		build(0, 0);
		cout << endl;
	}

	return 0;

}
