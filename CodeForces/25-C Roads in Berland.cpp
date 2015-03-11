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
#define sint(v) scanf("%d",&v);
#define sstr(v) scanf("%s",&v);
typedef long long ll;
using namespace std;

ll graph[302][302];
int main() {

	int n, k;
	sint(n);
	fo(i,n)
		fo(j,n)
			scanf("%I64d", &graph[i][j]);

	sint(k);
	fo(i,k) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		ll res = 0;
		fo(f,n)
			fo(t,n)
				graph[f][t] = graph[t][f] = min(graph[f][t], graph[f][a] + c
						+ graph[b][t]);
		fo(i,n)
			foo(j,i+1,n)
				res += graph[i][j];
		printf("%I64d ", res);
	}

	return 0;
}
