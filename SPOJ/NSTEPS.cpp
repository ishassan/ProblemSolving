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
#define rrepi(it,stl) for(typeof((stl).rbegin()) it = (stl).rbegin(); (it)!=stl.rend(); ++(it))
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

int arr[10010][2];
int main() {

	arr[0][0] = -1;
	arr[0][1] = 0;
	arr[1][0] = -1;
	arr[1][1] = 1;

	int cnt = 2;
	for (int i = 2; i <= 10000; i += 2) {
		arr[i][0] = cnt++;
		arr[i + 1][0] = cnt++;
		arr[i][1] = cnt++;
		arr[i + 1][1] = cnt++;

	}

	int tst, x, y;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d", &x, &y);

		if (x - y == 2 && arr[x][0] != -1)
			printf("%d\n", arr[x][0]);

		else if (x == y && arr[x][1] != -1)
			printf("%d\n", arr[x][1]);

		else
			printf("No Number\n");
	}
	return 0;
}
