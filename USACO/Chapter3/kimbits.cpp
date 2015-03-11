/*
 	 TASK:kimbits
 	 LANG: C++
 	 ID: fci_isl1
 */
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
#define foi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define SZ(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

ll memo[40][40];
ll DP(int len, int remOne) {
	if (len == 0 || remOne == 0)
		return 1;

	ll& m = memo[len][remOne];

	if (m != -1)
		return m;

	ll res = DP(len - 1, remOne);
	res += DP(len - 1, remOne - 1);

	return m = res;

}
int main() {

	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);

	int n, l;
	ll i;
	string str;
	scanf("%d%d%lld", &n, &l, &i);
	memset(memo, -1, sizeof memo);

	for (int j = 0; j < n; ++j) {
		ll res = DP(n - j - 1, l);
		if (res >= i)
			str += "0";
		else {
			str += "1";
			i -= res;
			l--;
		}
	}

	cout << str << endl;

	return 0;
}
