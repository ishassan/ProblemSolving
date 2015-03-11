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
typedef long long ll;
using namespace std;

char str[1002];
int main() {

	while (scanf("%s", str)) {
		if (str[0] == 'Q')
			return 0;

		set<pii> st;
		int x = 0, y = 0, res = 0;
		st.insert(mp(x,y));

		for (int i = 0; str[i] != 'Q'; ++i)
		{
			if (str[i] == 'U')
				y++;
			else if (str[i] == 'D')
				y--;
			else if (str[i] == 'R')
				x++;
			else if (str[i] == 'L')
				x--;

			res += !st.insert(mp(x,y)).second;
		}

		printf("%d\n", res);
	}
	return 0;
}
