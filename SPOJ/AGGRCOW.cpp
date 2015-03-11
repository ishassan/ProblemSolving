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
#define repe(i,m,n) for(int i=(m); i<=(n); i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int n, c;
int arr[100003];

bool can(int dist) {
	ll s = arr[0];
	int cc = c - 1;
	while (cc--) {
		s += dist;
		int* p = lower_bound(arr, arr + n, s);
		if (p == arr + n)
			return false;

		s = *p;
	}
	return true;
}
int main() {


	int tst;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d", &n, &c);
		rep(i,n)
			scanf("%d", arr + i);

		sort(arr, arr + n);

		int s = 1e9, e = arr[n-1];

		reps(i,1,n)
			s = min(s, arr[i] - arr[i - 1]);

		int lst = -1;
		while (s < e) {
			int mid = (s + (e - s) / 2);
			if (can(mid))
				lst = mid, s = mid + 1;
			else
				e = mid;
		}

		printf("%d\n", (lst==-1)?s:lst);
	}

	return 0;
}
