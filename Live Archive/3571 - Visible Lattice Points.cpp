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

int memo[1009];

int main() {
	//freopen("in.txt", "r", stdin);
	memo[0] = 0;
	foe(i,1,1000) {
		memo[i] = memo[i - 1];
		foe(j,0,i) {
			if (__gcd(i, j) == 1) {
				memo[i]++;
				if (i != j)
					memo[i]++;
			}
		}
	}

	int tst;
	scanf("%d", &tst);
	foe(t,1,tst) {
		int n;
		scanf("%d", &n);

		printf("%d %d %d\n", t, n, memo[n]);
	}
	return 0;

}
