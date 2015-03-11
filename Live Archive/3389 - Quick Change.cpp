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

int main() {

	int tst;
	scanf("%d", &tst);
	foe(t,1,tst) {
		int n, a = 0, b = 0, c = 0, d = 0;
		scanf("%d", &n);
		while (n >= 25)
			n -= 25, a++;

		while (n >= 10)
			n -= 10, b++;

		while (n >= 5)
			n -= 5, c++;

		while (n >= 1)
			n -= 1, d++;

		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",t,a,b,c,d);
	}

	return 0;
}
