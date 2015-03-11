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
#define mci map<char,int>::reverse_iterator
typedef long long ll;
using namespace std;

int memo[210][210];
int match[210];
int n;
int DP(int i, int j) {
	if (i == j)
		return 0;

	int&m = memo[i][j];
	if (m != -1)
		return m;

	m = n;
	for (int k = i; k < j; ++k)
		if (match[k] >= min(k - i, j - (k + 1))) {
			int c1 = DP(i, k);
			int c2 = DP(k + 1, j);
			m = min(m, max(c1, c2) + 1);
		}
	return m;
}

inline bool rev(char a, char b) {
	return (a == 'A' && b == 'V') || (a == 'V' && b == 'A');
}
int main() {
	char str[210];
	while (scanf("%s", str) != -1) {
		n = strlen(str);
		mem(memo,-1), mem(match,0);
		rep(i,n)
			for (int d = 1; i + d < n && i - d >= 0; ++d)
				if (rev(str[i + d], str[i - d]))
					++match[i];
				else	break;
		++n; //# segments instead of folds
		printf("%d\n", DP(0, n - 1));
	}
	return 0;
}
