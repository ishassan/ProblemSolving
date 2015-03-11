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

char str[2004];
int main() {

	int tst = 1;
	while (scanf("%s", str) && str[0] != '-') {
		int res = 0, cnt = 0, i;
		for (i = 0; str[i] != '\0'; ++i) {
			if (str[i] == '{')
				cnt++;
			else if (--cnt == -1) {
				cnt = 1;
				res++;
			}
		}
		for (--i,cnt=0; i >= 0; --i) {
			if (str[i] == '}')
				cnt++;
			else if (--cnt == -1) {
				cnt = 1;
				res++;
			}
		}
		printf("%d. %d\n",tst++, res);
	}

	return 0;
}
