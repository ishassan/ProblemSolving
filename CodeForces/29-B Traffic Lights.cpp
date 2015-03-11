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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

double sim(int g, int r, double t1) {
	double total = g + r;
	while (t1 > total)
		t1 -= total;

	if (t1 < g)
		return 0;
	return total - t1;
}
int main() {
	int l, d, v, g, r;
	scanf("%d%d%d%d%d", &l, &d, &v, &g, &r);

	double t1 = (double) d / v;
	double t2 = (double) (l - d) / v;

	double ts = sim(g, r, t1);

	printf("%.8lf\n", t1 + t2 + ts);

	return 0;
}
