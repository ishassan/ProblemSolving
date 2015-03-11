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
#include <climits>

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

vector<vi> adjlst;
const int MAX = 1 << 20, OO = 1 << 25;
int level[MAX];
int id[MAX];
int mapper[MAX];
bool par[MAX];

int Index = 0;
bool vis[MAX];
void DFS(int num, int lvl) {
	id[Index] = num;
	level[Index] = lvl;
	mapper[num] = Index++;
	repi(it, adjlst[num]) {
		DFS(*it, lvl + 1);
		id[Index] = num;
		level[Index++] = lvl;
	}
}

int segm[2 * MAX];

void build(int idx, int s, int e) {

	if (s == e) {
		segm[idx] = s;
		return;
	}
	build(2 * idx + 1, s, (s + e) / 2);
	build(2 * idx + 2, (s + e) / 2 + 1, e);
	if (level[segm[2 * idx + 1]] < level[segm[2 * idx + 2]])
		segm[idx] = segm[2 * idx + 1];
	else
		segm[idx] = segm[2 * idx + 2];
}

int getMin(int idx, int tars, int tare, int curs, int cure) {

	if (tars > cure || tare < curs)
		return OO;

	if (tars <= curs && tare >= cure)
		return segm[idx];

	int val1 = getMin(2 * idx + 1, tars, tare, curs, (curs + cure) / 2);
	int val2 = getMin(2 * idx + 2, tars, tare, (curs + cure) / 2 + 1, cure);
	if (val1 >= OO)
		return val2;
	if (val2 >= OO)
		return val1;

	if (level[val1] < level[val2])
		return val1;
	return val2;
}

int res[MAX];
int main() {

	int n;
	while (scanf("%d", &n) != -1) {
		adjlst.clear();
		adjlst.resize(n + 2);
		mem(res,0);
		mem(segm,0);
		mem(vis,0);
		mem(par,0);
		mem(mapper,0);
		mem(id,0);
		mem(level,0);
		rep(i,n) {
			int nd, ch, inp;
			scanf("%d:(%d)", &nd, &ch);
			rep(i,ch) {
				scanf("%d", &inp);
				adjlst[nd - 1].push_back(inp - 1);
				par[inp - 1] = true;
			}
		}

		int rt = -1;
		rep(i,n)
			if (!par[i]) {
				rt = i;
				break;
			}

		DFS(rt, 0);
		build(0, 0, Index - 1);

		int m, frm, to;
		scanf("%d", &m);

		char c;
		while (m--) {
			scanf(" %c%d%d %c", &c, &frm, &to, &c);
			--frm, --to;
			int idx1 = mapper[frm], idx2 = mapper[to];
			if (idx1 > idx2)
				swap(idx1, idx2);
			int r = getMin(0, idx1, idx2, 0, Index - 1);
			++res[id[r]];
		}

		repe(i,0,n)
			if (res[i])
				printf("%d:%d\n", i + 1, res[i]);
	}
	return 0;
}
