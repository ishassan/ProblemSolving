/*
 ID: fci_isl1
 LANG: C++
 PROB: comehome

 */
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

int n, d, o;
pair<pii, int> arr[25];

int range[25];
int DFS(int idx) {
	if (idx == o)
		return 0;

	int c1 = DFS(idx + 1);
	int c2 = -1e6;
	int s = arr[idx].first.first, e = arr[idx].first.second, p =
			arr[idx].second;
	bool novalid = 0;
	reps(i,s,e) {
		range[i] += p;
		if (range[i] > n)
			novalid = 1;
	}
	if (!novalid)
		c2 = DFS(idx + 1) + (e - s) * p;
	reps(i,s,e)
		range[i]-=p;
	return max(c1, c2);

}
int main() {

	int start, end, pass;
	while (scanf("%d%d%d", &n, &d, &o) && (n || d || o)) {
		mem(range,0);
		rep(i,o) {
			scanf("%d%d%d", &start, &end, &pass);
			arr[i] = mp(mp(start,end), pass);
		}
//		sort(arr, arr + o);
		printf("%d\n", DFS(0));
	}

	return 0;
}
