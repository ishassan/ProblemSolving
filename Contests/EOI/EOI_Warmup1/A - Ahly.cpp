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
#include <queue>
#include <set>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

struct state {
	int i, j;
	bool ahl;
};
int nums[500];
vector<int> memo[500][500][2];
int n;

vector<int> DP(state st) {
	vector<int> res(2);
	if (st.i > st.j)
		return res;

	vector<int>& m = memo[st.i][st.j][st.ahl];
	if (m[0] != -1 && m[1] != -1)
		return m;

	state tmp1 = { st.i + 1, st.j, !st.ahl };
	state tmp2 = { st.i, st.j - 1, !st.ahl };
	vector<int> c1 = DP(tmp1);
	vector<int> c2 = DP(tmp2);

	c1[st.ahl] += nums[st.i];
	c2[st.ahl] += nums[st.j];

	if (c1[st.ahl] > c2[st.ahl]) {
		return m = c1;
	}
	return m = c2;
}
int main() {
	int sum = 0;
	cin >> n;
	vector<int> v(2, -1);
	fo(i,500)
		fo(j,500)
			fo(k,2)
				memo[i][j][k] = v;
	fo(i,n)
		cin >> nums[i], sum += nums[i];

	state s = { 0, n - 1, 0 };
	vector<int> res = DP(s);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}

