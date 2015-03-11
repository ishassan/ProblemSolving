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

int arr[1010];

int memo[1010][1010][2];
bool vis[1010][1010][2];

int DP(int s, int e, bool t) {

	if (s > e)
		return 0;

	int& m = memo[s][e][t];
	if (vis[s][e][t])
		return m;

	int res = 0;
	if (t == 0) {
		int c1 = DP(s + 1, e, !t) + arr[s];
		int c2 = DP(s, e - 1, !t) + arr[e];
		res = max(c1, c2);
	}

	else {
		if (arr[s] >= arr[e])
			res =  DP(s + 1, e, !t) - arr[s];
		else
			res =  DP(s, e - 1, !t) - arr[e];
	}

	vis[s][e][t] = 1;
	return m = res;

}
int main() {

	int n;
	int tst = 1;
	while (scanf("%d", &n) && n) {
		rep(i,n)
			scanf("%d", arr + i);

		mem(vis,0);
		int res = DP(0, n - 1, 0);

		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",tst++, res);
	}

	return 0;
}
