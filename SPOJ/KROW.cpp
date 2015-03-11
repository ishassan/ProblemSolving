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

int h, w, k;

int rdir[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int cdir[8] = { 0, 1, -1, 0, 1, -1, 1, -1 };

char graph[205][205];

bool win(int i, int j) {
	rep(d,8) {
		bool valid = 1;
		rep(kk, k) {
			int newr = rdir[d] * kk + i;
			int newc = cdir[d] * kk + j;

			if (newr < 0 || newr >= h || newc < 0 || newc >= w) {
				valid = 0;
				break;
			}

			if (graph[i][j] != graph[newr][newc]) {
				valid = 0;
				break;
			}
		}

		if (valid)
			return 1;
	}
	return 0;
}
int main() {

	int tst;
	scanf("%d", &tst);
	int X = 0, O = 0;
	while (tst--) {
		scanf("%d%d%d", &w, &h, &k);

		rep(i,h)
			scanf("%s", graph[i]);

		rep(i,h)
			rep(j,w) {
				if (graph[i][j] == '.')
					continue;
				if (!win(i, j))
					continue;

				if (graph[i][j] == 'x')
					X++;
				else
					O++;
				goto END;
			}

		END: ;
	}

	printf("%d:%d\n", X, O);
	return 0;
}
