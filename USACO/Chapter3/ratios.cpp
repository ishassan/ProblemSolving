/*
 TASK: ratios
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

int goal[3];
int mix[3][3];
int fact[3];
int ratio[3];
int main() {

	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);

	fo(i,3)
		scanf("%d", goal + i);

	fo(i,3)
		fo(j,3)
			scanf("%d", &mix[i][j]);

	for (fact[0] = 0; fact[0] < 100; ++fact[0]) {

		for (fact[1] = 0; fact[1] < 100; ++fact[1]) {

			for (fact[2] = 0; fact[2] < 100; ++fact[2]) {

				memset(ratio,0,sizeof ratio);

				fo (i,3) {
					fo(j,3)
						ratio[j] += mix[i][j] * fact[i];
				}

				set<int> sol;

				fo(i,3) {
					if(goal[i]==0 && ratio[i]==0)
						continue;

					if ((goal[i] == 0 && ratio[i] != 0) || ratio[i] % goal[i]
							!= 0)
						goto failed;

					else if (goal[i])
						sol.insert(ratio[i] / goal[i]);
				}

				if (sol.size() == 1 && *sol.begin() != 0) {
					fo(i,3)
						printf("%d ", fact[i]);
					printf("%d\n", *sol.begin());
					return 0;
				}

				failed: ;
			}
		}
	}
	printf("NONE\n");

	return 0;
}
