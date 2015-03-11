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
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

double prob[102][102] = { {0} };
int main() {

	int n, m, f, t, p;
	while (scanf("%d%d", &n, &m) && n) {
		rep(i,n)	rep(j,n)	prob[i][j]=0;
		rep(i,m) {
			scanf("%d%d%d", &f, &t, &p);
			prob[f - 1][t - 1] = prob[t - 1][f - 1] = .01 * p;
		}

		rep(k,n)
			rep(i,n) {
				if (prob[i][k] < 1e-8)
					continue;
				rep(j,n)
					prob[i][j] = max(prob[i][j], prob[i][k] * prob[k][j]);
			}

		printf("%.6lf percent\n", prob[0][n - 1]*100);
	}
	return 0;
}
