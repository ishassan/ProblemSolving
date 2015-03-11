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

int main() {
	int n, ne = 0, no = 0, ie = -1, io = -1;
	int x;
	cin >> n;
	fo(i,n) {
		cin >> x;
		if (x % 2)
			no++, io = i+1;
		else
			ne++, ie = i+1;
	}
	if (no == 1)
		cout << io << endl;
	else
		cout << ie << endl;

	return 0;
}
