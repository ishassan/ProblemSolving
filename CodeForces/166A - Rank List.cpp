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
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())

typedef long long ll;
using namespace std;

bool cmp(pii a, pii b) {
	if(a.first > b.first) return 1;
	if(a.first == b.first && a.second < b.second) return 1;
	return 0;
}
int main() {
	int n, k;
	pair<int, int> arr[52];
	scanf("%d%d", &n, &k);
	rep(i,n) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	sort(arr, arr + n, cmp);
	pii p = arr[k-1];
	int cnt = 1;
	for (int i = k-2; i >=0; --i) {
		if(arr[i]==p) ++cnt;
	}
	for (int i = k; i < n; ++i) {
		if(arr[i]==p)++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
