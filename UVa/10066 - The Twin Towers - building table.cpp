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
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

int arr1[102], arr2[102];

int memo[102][102];

inline int max(int a, int b, int c) {
	return max(a, max(b, c));
}
int main() {

	int n, m;
	int t=1;
	while (cin >> n >> m && (n || m)) {
		fo(i,n)
			cin >> arr1[i];
		fo(j,m)
			cin >> arr2[j];

		//f(i,j) = max( f(i+1,j) , f(i,j+1) , f(i+1,j+1)+(arr1[i]==arr2[j]))
		fo(i,m)
			memo[n][i] = 0;
		fo(i,n)
			memo[i][m] = 0;

		for (int i = n - 1; i > -1; i--) {
			for (int j = m - 1; j > -1; j--) {
				memo[i][j] = max(memo[i + 1][j], memo[i][j + 1], memo[i + 1][j
						+ 1] + (arr1[i] == arr2[j]));
			}
		}

		printf("Twin Towers #%d\n",t++);
		printf("Number of Tiles : %d\n\n",memo[0][0]);

	}
	return 0;
}
