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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

//see HEAPULM for more details about implementation of order statistic tree
const int N = 1 << 17;
int ost[N + N];
int arr[N];

ll getMaxRec(int from, int to) {

	int minIdx = arr[ost[from]] <= arr[ost[to]] ? from : to;
	for (int f = from, t = to; f < t; f /= 2, t /= 2) {
		if (f + 1 < t && arr[ost[f + 1]] <= arr[ost[minIdx]])
			minIdx = f + 1;
		if (t - 1 > f && arr[ost[t - 1]] <= arr[ost[minIdx]])
			minIdx = t - 1;
	}

	//ost[minIdx] = index of min element in interval from-to
	//go down
	while (minIdx < N) {
		if (ost[minIdx] == ost[minIdx + minIdx])
			minIdx = minIdx + minIdx;
		else if (ost[minIdx] == ost[minIdx + minIdx + 1])
			minIdx = minIdx + minIdx + 1;
	}

	ll res = (ll)arr[ost[minIdx]] * (to - from + 1);
	if (from < minIdx)
		res = max(res, getMaxRec(from, minIdx - 1));
	if (minIdx < to)
		res = max(res, getMaxRec(minIdx + 1, to));
	return res;
}
int main() {

	int n;
	while (scanf("%d", &n) && n) {
		rep(i,n) {
			scanf("%d", arr + i);
			ost[N + i] = i;
		}

		for (int f = N, t = N + n - 1; f > 1; f /= 2, t /= 2) {
			for (int i = f; i < t; i += 2)
				ost[i / 2] = arr[ost[i]] <= arr[ost[i + 1]] ? ost[i] : ost[i
						+ 1];

			if (t % 2 == 0)
				ost[t / 2] = ost[t];
		}

		ll res = getMaxRec(N, N + n - 1);
		printf("%lld\n", res);
	}
	return 0;
}
