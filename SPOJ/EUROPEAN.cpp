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

int n;
int arr[10];
bool vis[10];
set<int> bst;

bool isfinal(set<int>& path) {
	rep(i,n) {
		if (!vis[i])
			return 0;
	}
	return 1;
}

void backtrack(set<int>& path) {
	if (sz(path) > 5 || sz(path) >= sz(bst))
		return;

//	if (isfinal(path)) {
//		bst = path;
//		return;
//	}

	bool stop = 1;
	reps(i,1,n) {
		if (vis[i])
			continue;

		stop=0;
		repi(it,path) {
			if (path.find(*it + arr[i]) != path.end()
					|| path.find(*it - arr[i]) != path.end()) {
				vis[i] = 1;
				backtrack(path);
				vis[i] = 0;
				return;
			}

		}

		repi(it,path) {
			vis[i] = 1;
			path.insert(arr[i] + *it);
			backtrack(path);
			path.erase(arr[i] + *it);

			path.insert(*it - arr[i]);
			backtrack(path);
			path.erase(*it - arr[i]);

			vis[i] = 0;
		}
	}

	if(stop)
		bst = path;

}
int main() {

//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);

	int tst;
	scanf("%d", &tst);
	repe(t,1,tst) {
		printf("Scenario #%d\n", t);
		mem(vis,0);
		bst.clear();
		scanf("%d", &n);
		rep(i,n) {
			scanf("%d", arr + i);
			bst.insert(arr[i]);
		}

		set<int> path;
		path.insert(0);
		path.insert(arr[0]);
		vis[0]=1;
		bst.insert(0);
		backtrack(path);
		printf("%d:", sz(bst));
		int offset = *bst.begin();
		repi(it,bst)
			printf(" %d", *it-offset);
		printf("\n\n");
	}

	return 0;
}
