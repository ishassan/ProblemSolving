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
pii lines[10002];

int main() {
	int n, m, a, b;
	while (scanf("%d%d", &n, &m) != -1 && (n || m)) {

		int sz = 0;
		fo(i,n)
			scanf("%d%d%d%d", &a, &b, &a, &b), lines[sz++] = (mp(a,a+b));

		fo(i,m) {
			int res = 0;
			scanf("%d%d", &a, &b);
			b = a + b;

			fo(s,sz) {

				if (a >= lines[s].first && a < lines[s].second)
					res++;
				else if (b > lines[s].first && b <= lines[s].second)
					res++;
				else if(a <= lines[s].first && b>= lines[s].second)
					res++;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
