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

vector<vector<int> > box;
vector<vector<int> > sorted;

int n, m;

int memo[32];

bool operator>(vector<int>& v1, vector<int>& v2) {
	fo(i,m)
		if (v1[i] <= v2[i])
			return 0;
	return 1;
}

int lis(int lst) {
	if (lst != -1 && memo[lst] != -1)
		return memo[lst];

	int mx = 0;
	fo(i,n)
		if (lst == -1 || sorted[i] > sorted[lst])
			mx = max(mx, lis(i) + 1);

	return (lst == -1) ? mx : memo[lst] = mx;
}

void build(int lst) {

	int mx = 0;
	int idx = -1;
	fo(i,n)
		if (lst == -1 || sorted[i] > sorted[lst]) {
			int l = lis(i) + 1;
			if (mx < l)
				mx = l, idx = i;
		}

	if (idx == -1)
		return;

	if (lst == -1)
		cout << idx + 1;
	else
		cout << " " << idx + 1;
	build(idx);

}
int main() {

	while (cin >> n >> m) {
		int tmp;
		box.clear();
		sorted.clear();
		memset(memo, -1, sizeof memo);

		fo(i,n) {
			vector<int> v;
			fo(j,m)
				cin >> tmp, v.push_back(tmp);
			box.push_back(v);
			sort(v.begin(), v.end());
			sorted.push_back(v);
		}

		cout << lis(-1) << endl;
		build(-1);
		cout << endl;
	}

	return 0;
}
