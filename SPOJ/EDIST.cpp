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

string a, b;
int memo[2010][2010];
int edit(int i, int j) {
	if (i == a.size())
		return b.size() - j;

	if (j == b.size())
		return a.size() - i;

	int &m = memo[i][j];
	if(m != -1)
		return m;

	if(a[i]==b[j])
		return m = edit(i+1,j+1);

	int c1 = edit(i,j+1)+1;
	int c2 = edit(i+1,j)+1;
	c2 = min(c2,edit(i+1,j+1)+1);

	return m = min(c1,c2);
}

int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		cin >> a >> b;
		memset(memo, -1, sizeof memo);
		cout << edit(0, 0) << endl;
	}
	return 0;
}
