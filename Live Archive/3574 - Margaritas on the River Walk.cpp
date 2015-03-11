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
typedef unsigned int ui;
using namespace std;

int n, total;
int arr[40];
ll memo[40][1010][40];

ll DP(int i, int sum, int mn) {
	if (sum > total)
		return 0;

	if (i == n) {
		if(total < arr[mn])
			return 0;

		if (mn < n)
			return (total - sum) < arr[mn];
		else
			return 1;
	}
	ll& m = memo[i][sum][mn];
	if (m != -1)
		return m;

	m = 0;
	m += DP(i + 1, sum, mn);
	if (i == mn)
		m += DP(i + 1, sum + arr[i],mn+1);
	else
		m += DP(i + 1, sum + arr[i],mn);

	return m;
}
int main() {

	int tst;
	scanf("%d", &tst);
	foe(t,1,tst) {
		memset(memo, -1, sizeof memo);

		scanf("%d %d", &n, &total);
		fo(i,n)
			scanf("%d", arr + i);

		sort(arr, arr + n);

		printf("%d %lld\n", t, DP(0, 0, 0));

	}

	return 0;
}
