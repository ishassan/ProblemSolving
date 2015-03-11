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
#define repe(i,m,n) for(int i=(m); i<=(n); i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int n;
int g[100003][3];
ll memo[100003][3];

ll DP(int i, int j){
	if(i==n-1 && j==1)
		return g[i][j];

	if(i>=n || j>2)
		return 1e8;

	ll& m = memo[i][j];
	if(m != -1)
		return m;

	m = DP(i,j+1) + g[i][j];
	m = min(m, DP(i+1,j) + g[i][j]);
	if(j==0){
		m = min(m, DP(i+1,j+1) + g[i][j]);
	}

	else if(j==1){
		m = min(m, DP(i+1,j-1) + g[i][j]);
		m = min(m, DP(i+1,j+1) + g[i][j]);
	}

	else if(j==2){
		m = min(m, DP(i+1,j-1) + g[i][j]);
	}

	return m;
}
int main() {

	int tst=1;
	while (scanf("%d", &n) && n) {
		rep(i,n)
			scanf("%d%d%d", &g[i][0], &g[i][1], &g[i][2]);

		mem(memo,-1);
		printf("%d. %lld\n",tst++,DP(0,1));

	}

	return 0;
}
