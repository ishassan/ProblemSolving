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
#include <bitset>

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
typedef long long ll;
using namespace std;

bitset<(1 << 18) + 3> vis;
int move[12][12] = { { }, { 0, 1, 3, 4 }, { 0, 1, 2 }, { 1, 2, 4, 5 },
		{ 0, 3, 6 }, { 1, 3, 4, 5, 7 }, { 2, 5, 8 }, { 3, 4, 6, 7 },
		{ 6, 7, 8 }, { 4, 5, 7, 8 } };

int size[12]={0,4,3,4,3,5,3,4,3,4};
bool done = false;
int arr[20] = { 0 };

int apply(int state, int nmove) {
	if (nmove == 0)
		return state;

	for (int i = 8; i >= 0; --i) {
		arr[i] = state & 3;
		state = state >> 2;
	}

	rep(i,size[nmove]) {
		if ((++arr[move[nmove][i]]) > 3)
			arr[move[nmove][i]] = 0;
	}

	for (int i = 0; i < 9; ++i) {
		state = state << 2;
		state |= arr[i];
	}

	return state;

}

void print(vi& path) {
	rep(i,sz(path)-1)
		printf("%d ", path[i]);
	printf("%d\n", path.back());
}

void DFS(int nmove, int state, vi path) {
	if (state == 0) {
		print(path);
		done = true;
		return;
	}

	repe(i,nmove,9) {
		if (done)
			return;

		int siz = sz(path);
		if (siz >= 3 && i == path[siz - 1] && i == path[siz - 2] && i
				== path[siz - 3])
			continue;

		int nxt = apply(state, i);
		if (vis[nxt])
			continue;

		vis[nxt] = true;
		path.push_back(i);
		DFS(i, nxt, path);
		path.pop_back();
		vis[nxt] = false;
	}

}
int main() {

	int state = 0, n;
	rep(i,9) {
		scanf("%d", &n);
		state = state << 2;
		state |= n;
	}
	vi path;
	vis[state] = true;
	DFS(0, state, path);

	return 0;
}

