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
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

const int SIZE = 100;
int r;
int offset[SIZE], ncol[SIZE];
bool vis[SIZE][SIZE];

int di[8] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dj[8] = { -2, 2, 1, -1, 2, -2, 1, -1 };

int Res = 1 << 27;
int N;
void DFS(int i, int j, int mark) {
	bool fail = 1;
	rep(d,8) {
		int newi = i + di[d];
		int newj = j + dj[d];

		if (newi < 0 || newi >= r || newj < offset[newi] || newj
				>= (offset[newi] + ncol[newi]) || vis[newi][newj])
			continue;

		vis[newi][newj] = 1;
		fail = 0;
		DFS(newi, newj, mark + 1);
		vis[newi][newj] = 0;
	}

	if (fail) {
		Res = min(Res, N - mark);
	}
}
int main() {

	int tst = 1;
	while (scanf("%d", &r) && r) {
		Res = 1 << 27;
		mem(vis,0);
		mem(offset,0);
		mem(ncol,0);
		N = 0;
		rep(i,r)
			scanf("%d%d", &offset[i], &ncol[i]), N += ncol[i];

		vis[0][offset[0]] = 1;
		DFS(0, offset[0], 1);

		if (Res == 1)
			printf("Case %d, %d square can not be reached.\n", tst++, Res);
		else
			printf("Case %d, %d squares can not be reached.\n", tst++, Res);

	}
	return 0;
}
