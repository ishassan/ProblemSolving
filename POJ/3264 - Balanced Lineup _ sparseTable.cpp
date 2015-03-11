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
#include <list>
#include <climits>
#include <assert.h>
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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

const int N = 50010;
const int LOGN = 17;
int rmq[N][LOGN], rxq[N][LOGN];
int arr[N];
int n, m;

void build() {
	rep(i,n)
		rmq[i][0] = rxq[i][0] = arr[i];

	for (int j = 1; 1 << j <= N; ++j) {
		for (int i = 0; i + (1 << j) - 1 < N; ++i) {
			rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1)) ][j - 1]);
			rxq[i][j] = max(rxq[i][j - 1], rxq[i + (1 << (j - 1)) ][j - 1]);
		}
	}
}

int getRMQ(int i, int j) {
	int k = log2(j - i + 1);
	return min(rmq[i][k], rmq[j - (1 << k) + 1][k]);
}
int getRXQ(int i, int j) {
	int k = log2(j - i + 1);
	return max(rxq[i][k], rxq[j - (1 << k) + 1][k]);
}

int main() {

	scanf("%d%d", &n, &m);
	rep(i,n)
		scanf("%d", &arr[i]);
	build();
	int a, b;
	rep(i,m) {
		scanf("%d%d", &a, &b), --a, --b;
		printf("%d\n", getRXQ(a, b) - getRMQ(a, b));
	}

	return 0;
}
