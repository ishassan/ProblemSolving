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

int m,arr[12];
int calc(int i, int j){
	int q = (arr[j] - arr[i]) / arr[i];
	return  m * q;
}

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int tst;
	scanf("%d", &tst);
	repe(t,1,tst) {
		printf("Case #%d: ", t);
		scanf("%d", &m);
		rep(i,12)
			scanf("%d", &arr[i]);

		int b = -1, s = -1, bst = 0;
		rep(i,12) {
			if (m < arr[i])
				continue;
			reps(j,i+1,12) {
				if(arr[j] <= arr[i])
					continue;
				if (calc(i,j) > bst) {
					bst = calc(i,j);
					b = i, s = j;
				} else if (calc(i,j) == bst) {
					if (arr[i] < arr[b])
						b = i, s = j;
				}
			}
		}

		if (b == -1) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		printf("%d %d %d\n", b + 1, s + 1, bst);

	}
	return 0;
}
