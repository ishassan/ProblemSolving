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
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int n, start, end;

int arr[40];

int lhs[(1 << 17) + 3], rhs[(1 << 17) + 3];
int lx = 0, rx = 0;
int main() {
	//Convert int to ll

	ll res = 0;
	scanf("%d%d%d", &n, &start, &end);

	rep(i,n)
		scanf("%d", arr + i);

	int lim1 = n / 2, lim2=(n+1)/2;

	rep(i,1<<lim1) {
		int tmp = 0;
		rep(j,lim1) {
			if (i & (1 << j))
				tmp += arr[j];
		}

		lhs[lx++] = tmp;
	}

	sort(lhs, lhs + lx);


	rep(i,1<<lim2) {
		int tmp = 0;
		rep(j,lim2) {
			if (i & (1 << j))
				tmp += arr[lim1 + j];
		}

		rhs[rx++] = tmp;
	}

	sort(rhs, rhs + rx);

	rep(i,lx) {
		int s = start - lhs[i];
		int e = end - lhs[i];

		res += upper_bound(rhs, rhs + rx, e) - lower_bound(rhs, rhs + rx, s);
	}

	printf("%lld\n", res);

	return 0;
}
