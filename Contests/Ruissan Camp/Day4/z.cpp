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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int n;
void perm(int i, int o, int c, string res) {
	if (i >= 2 * n) {
		cout << res << endl;
		return;
	}

	if (c == o) {
		perm(i + 1, o + 1, c, res + "(");

	}

	else if (c < o && o<n) {
		perm(i + 1, o + 1, c, res + "(");
		perm(i + 1, o, c + 1, res + ")");
	}

	else if(o==n){
		perm(i + 1, o, c+1, res + ")");
	}
}
int main() {

	freopen("paren.in", "r", stdin);
	freopen("paren.out", "w", stdout);

	cin >> n;
	perm(0, 0, 0,"");
	return 0;
}
