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

int n, d;
ll l;
int w8[100002];
ll x[100002];

bool valid(int ncars) {
	ll cost = 0;
	fo(i,ncars)
		cost += (w8[i] * x[ncars - 1]) / d;
	return (cost <= l);
}
int main() {

	cin >> n >> d >> l;
	fo(i,n)
		cin >> w8[i];
	fo(i,n)
		cin >> x[i];

	sort(w8, w8 + n);

	int low = 1, hi = n;
	int res = 0;
	while (low <= hi) {
		int mid = (low + hi) / 2;
		if (valid(mid)) {
			res = mid;
			low = mid + 1;
		} else
			hi = mid - 1;
	}

	cout << res << endl;
	return 0;
}

