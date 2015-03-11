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

int lst[4002][4];
int lhs[16000002];
int main() {

	int n;
	scanf("%d", &n);
	fo(i,n)
	fo(j,4)
		scanf("%d", &lst[i][j]);

	int sz=0;
	fo(i,n)
	fo(ii,n)
		lhs[sz++] = lst[i][0] + lst[ii][1];

	sort(lhs,lhs+sz);
	int res=0;
	fo(i,n)
	fo(ii,n){
		int val = lst[i][2]+lst[ii][3];
		res += upper_bound(lhs,lhs+sz,-val) - lower_bound(lhs,lhs+sz,-val);
	}

	printf("%d\n",res);
	return 0;
}
