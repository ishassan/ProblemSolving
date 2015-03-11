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
#define pdi pair<double,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define mit map<int, string>::iterator
typedef long long ll;
using namespace std;


int n,m;
int cost[102], fun[102];
int OO = 1<<29;

pii memo[102][502];

pii operator+ (pii a, pii b){
	return mp(a.first + b.first, a.second + b.second);
}

pii DP(int idx, int rest){	//(fun,cost)
	if(rest < 0)
		return mp(-OO, OO);
	if(idx==n)
		return mp(0,0);

	pii& m = memo[idx][rest];
	if(m.first != -1)
		return m;

	pii c1 = DP(idx+1, rest-cost[idx]) + mp(fun[idx], cost[idx]);
	pii c2 = DP(idx+1, rest);

	if(c1.first == c2.first)
		m = c1.second < c2.second ? c1 : c2;
	else
		m = c1.first > c2.first ? c1 : c2;

	return m;
}

int main() {
	while (scanf("%d%d", &m, &n) && (m || n)) {
		rep(i,n)
			scanf("%d%d", cost + i, fun + i);

		mem(memo,-1);
		pii res = DP(0,m);
		printf("%d %d\n",res.second, res.first);
	}

	return 0;
}
