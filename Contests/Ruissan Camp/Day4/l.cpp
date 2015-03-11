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

int g[110][110];

void floyd(int n) {
	foe(k,1,n)
		foe(i,1,n)
			foe(j,1,n)
				if (g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
}
int main() {

	freopen("average.in", "r", stdin);
	freopen("average.out", "w", stdout);

	int n, k, a, b, c;
	cin >> n >> k;

	fo(i,110)
		fill(g[i],g[i]+110,1e7);

	fo(i,k) {
		cin >> a >> b >> c;
		g[a][b] = min(c,g[a][b]);
	}

	floyd(n);
	int sz=0;
	int sum=0;
	foe(i,1,n)
		foe(j,1,n){
		if(g[i][j]>=1e7 || i==j)
			continue;
		++sz;
		sum += g[i][j];
	}

	double res = (double)sum/sz;
	printf("%.6lf\n",res+1e-9);

	return 0;
}
