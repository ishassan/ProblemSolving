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

int main() {

	int a, b;
	while (scanf("%d%d", &a, &b) != -1) {
		if (a == -1 && b == -1)
			return 0;

		if (a == 1 || b == 1)
			printf("%d+%d=%d\n", a, b, a + b);
		else
			printf("%d+%d!=%d\n", a, b, a + b);
	}

	return 0;
}
