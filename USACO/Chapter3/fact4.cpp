/*
 	 TASK:fact4
 	 ID: fci_isl1
 	 LANG: C++
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

int main() {

	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);

	int n;
	scanf("%d", &n);

	int res = 1, two = 0, five = 0;
	for (int i = 2; i <= n; ++i) {
		int tmp = i;

		while (tmp % 2 == 0)
			++two, tmp /= 2;

		while (tmp % 5 == 0)
			++five, tmp /= 5;
	}

	int ten = min(two, five);
	two = five = ten;
	for (int i = 2; i <= n; ++i) {
		int tmp = i;

		while (tmp % 2 == 0 && two)
			tmp /= 2, --two;

		while (tmp % 5 == 0 && five)
			tmp /= 5, --five;

		res = (res*tmp)%10;
	}

	printf("%d\n", res);

	return 0;
}
