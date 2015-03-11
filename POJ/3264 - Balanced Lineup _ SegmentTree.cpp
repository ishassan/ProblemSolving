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

const int N = 50010, OO = 1<<27;
const int SIZE = (1<<16)+9;
int arr[N], segm[2*SIZE], segx[2*SIZE];
int n, m;

void build(int idx, int s, int e) {
	if (s == e) {
		segm[idx] = segx[idx] = arr[s];
		return;
	}
	build(2 * idx + 1, s, (s + e) / 2);
	build(2 * idx + 2, (s + e) / 2 + 1, e);

	segm[idx] = min(segm[2 * idx + 1], segm[2 * idx + 2]);
	segx[idx] = max(segx[2 * idx + 1], segx[2 * idx + 2]);
}

int getMin(int idx, int tars, int tare, int curs, int cure){
	if(tars > cure || tare < curs)
		return OO;

	if(tars <= curs && tare >= cure)
		return segm[idx];

	int val1 = getMin(2*idx+1, tars, tare, curs, (curs+cure)/2);
	int val2 = getMin(2*idx+2, tars, tare, (curs+cure)/2+1, cure);

	return min(val1, val2);
}

int getMax(int idx, int tars, int tare, int curs, int cure){
	if(tars > cure || tare < curs)
		return -OO;

	if(tars <= curs && tare >= cure)
		return segx[idx];

	int val1 = getMax(2*idx+1, tars, tare, curs, (curs+cure)/2);
	int val2 = getMax(2*idx+2, tars, tare, (curs+cure)/2+1, cure);

	return max(val1, val2);
}
int main() {

	scanf("%d%d", &n, &m);
	rep(i,n)
		scanf("%d", &arr[i]);
	build(0,0,n-1);
	int a, b;
	rep(i,m) {
		scanf("%d%d", &a, &b), --a, --b;
		printf("%d\n", getMax(0,a,b,0,n-1) - getMin(0,a,b,0,n-1));
	}

	return 0;
}
