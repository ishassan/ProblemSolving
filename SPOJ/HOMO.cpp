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
#include <hash_map>
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
using namespace __gnu_cxx;

hash_map<int, int> m, homog;
int main() {
	int tst, n;
	char str[10];
	scanf("%d", &tst);
	while (tst--) {
		scanf("%s%d", str, &n);
		if (!strcmp(str, "insert")) {
			if (++m[n] > 1)
				homog[n] = 1;
		}

		else if (m.find(n) != m.end()) {
			if (--m[n] == 0)
				m.erase(n);
			else if (m[n] == 1 && homog.find(n) != homog.end())
				homog.erase(n);
		}

		if(sz(m)==0){
			printf("neither\n");
			continue;
		}
		if (sz(m) == 1) {
			if (m.begin()->second == 1)
				printf("neither\n");
			else
				printf("homo\n");
			continue;
		}
		//must be hetero, may be both
		if (sz(homog))	printf("both\n");
		else			printf("hetero\n");
	}

	return 0;
}
