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
typedef long long ll;
using namespace std;

vector<int> nums;
int par[1000000];
int memo[1000000];
int sz;
int lis(int lst) {

	if (memo[lst] != -1)
		return memo[lst];

	int res = 0;
	foo(i,lst+1,sz) {
		if (nums[i] > nums[lst]) {
			int r = lis(i) + 1;
			if (res < r)
				res = r, par[lst] = i;
		}
	}

	return memo[lst] = res;
}

void build() {
	int l = par[0];
	while (l != -1) {
		cout << nums[l] << endl;
		l = par[l];
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
		memset(par, -1, sizeof par);
		nums.push_back(-(1 << 27));
		while (getline(cin, str) && str != "")
			nums.push_back(atoi(str.c_str()));

		sz = nums.size();
		cout << "Max hits: " << lis(0) << endl;
		build();
	}

	return 0;
}
