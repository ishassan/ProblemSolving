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

vector<int> nums;
pair<int, int> par[2000][2000];
int memo[2000][2000];
int sz;
int lis(int cur, int lst) {
	if (cur >= sz)
		return 0;

	if (memo[cur][lst] != -1)
		return memo[cur][lst];

	int c1 = lis(cur + 1, lst);
	int c2 = 0;
	if (nums[cur] > nums[lst])
		c2 = lis(cur + 1, cur) + 1;

	if (c1 >= c2) {
		par[cur][lst] = mp(cur + 1, lst);
		return memo[cur][lst] = c1;
	}

	par[cur][lst] = mp(cur + 1, cur);
	return memo[cur][lst] = c2;

}

void build() {
	pair<int, int> p = par[1][0];
	int lastl = 0;
	while (1) {
		if (p.second >= sz)
			break;
		if (p.first == -1 && p.second == -1)
			break;

		if (lastl != p.second)
			cout << nums[p.second] << endl;
		lastl = p.second;
		p = par[p.first][p.second];

	}
}
int main() {

	int tst;
	string str;
	cin >> tst;
	getline(cin, str);
	getline(cin, str);
	string end = "";
	while (tst--) {
		nums.clear();
		cout << end;
		end = "\n";
		memset(memo, -1, sizeof memo);
		memset(par,-1,sizeof par);
		nums.push_back(-(1 << 27));
		while (getline(cin, str) && str != "")
			nums.push_back(atoi(str.c_str()));

		sz = nums.size();
		cout << "Max hits: " << lis(1, 0) << endl;
		build();
	}

	return 0;
}

