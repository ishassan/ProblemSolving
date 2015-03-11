/*
 TASK: spin
 LANG: C++
 ID: fci_isl1
 */
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
#define foi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define SZ(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

bool wheel[5][360];
int speed[5], start[5];

int main() {

	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);

	int n, a, b;
	fo(i,5) {
		scanf("%d", speed + i);
		scanf("%d", &n);
		fo(j,n) {
			scanf("%d%d", &a, &b);
			int cnt = b+1;
			while (cnt--) {
				wheel[i][a++] = 1;
				if (a == 360)
					a = 0;
			}
		}
	}

	for (int t = 0; t < 360; ++t) {

		bool wall;

		fo(d,360) {
			wall = true;
			fo(w,5) {
				wall &= wheel[w][(start[w] + d)%360];
			}


		if (wall) {
			printf("%d\n", t);
			return 0;
		}
		}
		fo(w,5) {
			start[w] -= speed[w];
			if (start[w] < 0)
				start[w] += 360;
		}

	}

	printf("none\n");

	return 0;
}
