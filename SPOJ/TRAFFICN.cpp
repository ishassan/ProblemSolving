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

int n, m, k, f, t;
const int SIZE = 10004, OO = 1 << 27;

int DijkstraWithHeap(int src, int goal, vector<vector<pii> >& adjlst,
		int dist[SIZE]) {
	fill(dist, dist + n, OO);
	dist[src] = 0;
	priority_queue<pii, vector<pii> , greater<pii> > q;
	q.push(mp(0,src));
	while (q.size()) {
		src = q.top().second;
		int cst = q.top().first;
		q.pop();
		if (cst != dist[src])
			continue;
		if (src == goal)
			return dist[goal];
		repi(it, adjlst[src]) {
			int nxt = it->second, nxtc = it->first;
			if (dist[nxt] > dist[src] + nxtc) {
				dist[nxt] = dist[src] + nxtc;
				q.push(mp(dist[nxt],nxt));
			}
		}
	}
	return OO;
}

int main() {
	int tst, a, b, c;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d%d%d%d", &n, &m, &k, &f, &t), --f, --t;
		vector<vector<pii> > adjlstF(n), adjlstT(n);
		int distF[SIZE], distT[SIZE];
		rep(i,m) {
			scanf("%d%d%d", &a, &b, &c), --a, --b;
			adjlstF[a].push_back(mp(c,b));
			adjlstT[b].push_back(mp(c,a));
		}

		int ft = DijkstraWithHeap(f, t, adjlstF, distF);
		DijkstraWithHeap(t, f, adjlstT, distT);

		int mn = ft;
		rep(i,k) {
			scanf("%d%d%d", &a, &b, &c), --a, --b;
			if (mn > (distF[a] + c + distT[b]))
				mn = (distF[a] + c + distT[b]);
			if (mn > (distF[b] + c + distT[a]))
				mn = (distF[b] + c + distT[a]);
		}

		printf("%d\n",mn==OO?-1:mn);
	}


	return 0;
}
