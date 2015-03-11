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
typedef long long ll;
using namespace std;

const int MAX = 16;
int n;
int price[MAX], area[MAX];
double discount[MAX][MAX];
double memo[1<<MAX];
double best;

int main() {

	while(scanf("%d",&n) && n){
		rep(i,MAX)	rep(j,MAX)	discount[i][j] = 1.0;
		best = 1e20;
		rep(i,n){
			int k;
			scanf("%d%d%d",price+i, area+i, &k);
			while(k--){
				int idx,per;
				scanf("%d%d",&idx,&per);
				discount[i][idx-1] = (100-per)/100.0;
			}
		}

		int lim = 1<<n;
		rep(i,lim)
			memo[i] = 1e20;
		memo[0]=0;

		for (int mask = 0; mask < lim; ++mask) {
			int ar=0;
			for (int i = 0; i < n; ++i) {
				if(mask & (1<<i)){	//already taken
					ar += area[i];
					continue;
				}

				//take it
				double cost = price[i];
				rep(j,n)
					if((1<<j) & mask)
						cost *= discount[j][i];

				if(memo[mask] + cost < memo[mask | (1<<i)])
					memo[mask | (1<<i)] = memo[mask] + cost;
			}

			if(mask)
				best = min(best, memo[mask]/ar);

		}
		printf("%.4lf\n",best);
	}

	return 0;
}
