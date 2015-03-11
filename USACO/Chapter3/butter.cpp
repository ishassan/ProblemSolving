/*
 TASK: butter
 LANG: C++
 ID: fci_isl1
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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define foi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define SZ(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

const int MAX = 1002;
bool vis[MAX];
int d[MAX][MAX];
int N;
vector<pair<int, int> > adjlst[810];

void dijkstraHeap(int start) {

	fill(d[start], d[start] + N + 2, 1e6);
	memset(vis, 0, sizeof vis);
	d[start][start] = 0;

	priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int,
			int> > > Q;
	Q.push(make_pair(0, start));

	while (!Q.empty()) {
		pair<int, int> S = Q.top();
		Q.pop();

		if (vis[S.second])
			continue;

		vis[S.second] = 1;

		for (int i = 0; i < (int) adjlst[S.second].size(); i++) {
			pair<int, int> j = adjlst[S.second][i];

			if (!vis[j.first] && d[start][S.second] + j.second
					< d[start][j.first]) {
				d[start][j.first] = d[start][S.second] + j.second;
				Q.push(make_pair(d[start][j.first], j.first));
			}
		}
	}
}

int req[510];
int main() {

	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);

	int n, lnk;
	scanf("%d%d%d", &n, &N, &lnk);

	fo(i,n)
		scanf("%d", req + i);

	fo(i,lnk) {
		int from, to, len;
		scanf("%d%d%d", &from, &to, &len);
		adjlst[from].push_back(mp(to,len));
		adjlst[to].push_back(mp(from,len));
	}

	fo(i,n)
		dijkstraHeap(req[i]);

	int mn = 1e9;
	foe(i,1,N) {
		int sum = 0;
		fo(j,n) {
			sum += d[req[j]][i];
		}

		mn = min(sum, mn);
	}

	printf("%d\n", mn);

	return 0;
}
