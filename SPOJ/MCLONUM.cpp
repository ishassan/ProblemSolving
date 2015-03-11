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
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
char a[61], b[61], res[61];
int blen;

bool vis[61];

bool solve(int idx, bool gtr) {
	if (idx == blen)
		return 1;
	int start = 0;
	if (!gtr)
		start = lower_bound(b, b + blen, a[idx]) - b;

	for (int i = start; i < blen; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			res[idx] = b[i];
			if (solve(idx + 1, gtr || (b[i] > a[idx])))
				return 1;

			vis[i] = 0;
		}
	}
	return 0;

}

bool solve2(int idx, bool ls) {
	if (idx == blen)
		return ls;
	int start = blen - 1;
	if (!ls)
		start = upper_bound(b, b + blen, a[idx]) - b - 1;

	for (int i = start; i >= 0; --i) {
		if (idx == 0 && b[i] == '0')
			continue;
		if (!vis[i]) {
			vis[i] = 1;
			res[idx] = b[i];
			if (solve2(idx + 1, ls || (b[i] < a[idx])))
				return 1;

			vis[i] = 0;
		}
	}
	return 0;

}
int main() {

	cin >> a >> b;
	blen = strlen(b);
	sort(b, b + blen);
	if (solve(0, 0)) {
		cout << res << endl;

	} else
		cout << 0 << endl;
	mem(vis,0);
	if (solve2(0, 0)) {
		cout << res << endl;
	}
	else
		cout<<0<<endl;

	return 0;
}
