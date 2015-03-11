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

int n;

vector<pair<pair<int,int> , int> > orders;

int memo[10010];
int DP(int idx){

	if(idx==n)
		return 0;

	int& m = memo[idx];
	if(m!= -1)
		return m;

	int c1 = DP(idx+1);

	int end = orders[idx].first.first + orders[idx].first.second;
	int nxtidx = lower_bound(all(orders), mp( mp(end,0) , 0)) - orders.begin();

	int c2 = orders[idx].second + DP(nxtidx);

	return m = max(c1,c2);
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d",&n);
		orders.clear();
		orders.resize(n);

		pair<pair<int,int> , int> p;
		rep(i,n){
			scanf("%d%d%d",&p.first.first,&p.first.second,&p.second);
			orders[i] = p;
		}
		mem(memo,-1);
		sort(all(orders));
		printf("%d\n",DP(0));
	}
	return 0;
}
