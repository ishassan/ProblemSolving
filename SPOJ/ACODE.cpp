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

int sz;
string str;
ll memo[5002];

ll DP(int idx) {
	if (idx == sz)
		return 1;

	if(str[idx]=='0')
		return 0;

	if (memo[idx] != -1)
		return memo[idx];

	ll res = DP(idx + 1);
	if (idx + 1 < sz) {
		if (str[idx] == '1')
			res += DP(idx + 2);
		else if (str[idx] == '2' && str[idx + 1] < '7')
			res += DP(idx + 2);
	}

	return memo[idx] = res;
}
int main() {

	while (cin >> str && str != "0") {
		sz = str.size();
		memset(memo, -1, sizeof memo);
		cout << DP(0) << endl;
	}

	return 0;
}
