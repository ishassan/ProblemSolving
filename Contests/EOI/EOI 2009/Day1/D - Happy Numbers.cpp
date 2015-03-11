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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

set<ll> s;
int main() {
	int n;
	cin >> n;

	ll res = 0, sum = n, tmp;
	while (++res) {
		tmp = sum;
		sum = 0;
		while (tmp) {
			int i = tmp % 10;
			sum += i * i;
			tmp /= 10;
		}
		if (sum == 1)
			break;

		if (s.find(sum) != s.end()) {
			cout << -1 << endl;
			return 0;
		}

		s.insert(sum);
	}

	cout << res << endl;
	return 0;
}
