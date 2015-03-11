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

int s[102];
int lhs[1000002];

int main() {

	int n;
	scanf("%d", &n);
	fo(i,n)
	scanf("%d", s + i);

	int li = 0;
	fo(a,n)
	foo(b,a,n)
	fo(c,n) {
		lhs[li++] = s[a] * s[b] + s[c];
		if (b > a)
		lhs[li++] = s[a] * s[b] + s[c];
		}

	sort(lhs, lhs + li);
	int res = 0;

	fo(d,n) {
		if (s[d] == 0)	continue;
		fo(e,n)
			foo(f,e,n) {
				int rhs = s[d] * (s[e] + s[f]);
				int val = upper_bound(lhs, lhs + li, rhs) - lower_bound(lhs,
						lhs + li, rhs); //how many "rhs" values in lhs
				res += val;
				if (f > e)
					res += val;
			}
	}

	printf("%d\n", res);
	return 0;
}

