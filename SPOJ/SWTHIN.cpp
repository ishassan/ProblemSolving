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
pii pnt[1500];

int main() {

	int n;
	int tst = 1;
	while (scanf("%d", &n) && n) {
		int x, y;
		rep(i,n) {
			scanf("%d%d", &x, &y);
			pnt[i] = mp(x,y);
		}

		int mx = 0;
		rep(i,n) {
			int ver = 0;
			map<double, int> freq;

			reps(j,i+1,n) {
				x = pnt[i].first - pnt[j].first;
				y = pnt[i].second - pnt[j].second;

				if (!y)
					ver++;
				else
					freq[(double)x/y]++;
			}


			mx = max(mx, ver);
			repi(it,freq)
				mx = max(mx, it->second);
		}

		mx++;
		if (mx < 4)
			mx = 0;
		printf("Photo %d: %d points eliminated\n", tst++, mx);
	}

	return 0;
}
