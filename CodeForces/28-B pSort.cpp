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
typedef unsigned int ui;
using namespace std;

int n;
int target[110], fav[110];
int g[110][110];

void floyd() {
	fo(k,n)
		fo(i,n)
			fo(j,n)
				g[i][j] |= (g[i][k] & g[k][j]);
}

int main() {

	scanf("%d", &n);
	fo(i,n)
		scanf("%d", target + i), target[i]--;
	fo(i,n)
		scanf("%d", fav + i);

	fo(i,n) {
		g[i][i]=1;
		if (i + fav[i] < n)
			g[i][i + fav[i]] = g[i + fav[i]][i] = 1;
		if (i - fav[i] >= 0)
			g[i][i - fav[i]] = g[i - fav[i]][i] = 1;
	}

	floyd();
	bool b = 1;
	fo(i,n)
		if (!g[i][target[i]]) {
			b = 0;
			break;
		}

	printf((b) ? "YES\n" : "NO\n");

	return 0;
}
