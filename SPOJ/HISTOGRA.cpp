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
#include <list>
#include <climits>
#include <assert.h>
#include <map>

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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

int n;
const int SIZE = 1 << 17, OO = 1 << 27;

int arr[SIZE];
int rmq[2 * SIZE];

void build(int idx, int s, int e) {
	if (s == e) {
		rmq[idx] = s;
		return;
	}

	build(2 * idx + 1, s, (s + e) / 2);
	build(2 * idx + 2, (s + e) / 2 + 1, e);

	if (arr[rmq[2 * idx + 1]] < arr[rmq[2 * idx + 2]])
		rmq[idx] = rmq[2 * idx + 1];
	else
		rmq[idx] = rmq[2 * idx + 2];
}

int getMin(int idx, int tars, int tare, int curs, int cure) {

	if (tars > cure || tare < curs)
		return OO;

	if (tars <= curs && tare >= cure)
		return rmq[idx];

	int mn1 = getMin(2 * idx + 1, tars, tare, curs, (curs + cure) / 2);
	int mn2 = getMin(2 * idx + 2, tars, tare, (curs + cure) / 2 + 1, cure);

	if (mn1 == OO)
		return mn2;
	if (mn2 == OO)
		return mn1;

	if (arr[mn1] < arr[mn2])
		return mn1;
	return mn2;
}

ll calc(int s, int e) {
	if (s == e)
		return arr[s];

	int mnidx = getMin(0, s, e, 0, n - 1);

	if(mnidx == OO)
		return -OO;

	ll mx = (ll)arr[mnidx] * (e - s + 1);
	mx = max(mx, calc(s, mnidx - 1)); //* (mnidx - s)
	mx = max(mx, calc(mnidx + 1, e));
	return mx;
}
int main() {

	while (scanf("%d", &n) && n) {
		rep(i,n)
			scanf("%d", arr + i);
		build(0, 0, n - 1);

		printf("%lld\n",calc(0, n-1));

	}
	return 0;
}
