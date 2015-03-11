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
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;



struct edge {
	int f, t, c;
	bool cap;
};

vector<edge> E;
int prv[20000];

int bellman(int s, int d, bool Min) {
	vector<int> dist(d + 1, (Min ? (1 << 20) : -1 * (1 << 20)));
	vector<int> Flow(d + 1, 0);
	memset(prv, -1, sizeof(prv));

	dist[s] = 0;
	Flow[s] = (1 << 20);
	bool relax;
	for (int i = d; i >= 0; --i) {
		relax = false;
		for (int j = 0; j < E.size(); ++j) {
			if (E[j].cap) {
				if ((Min ? (dist[E[j].f] + E[j].c < dist[E[j].t]) : (dist[E[j].f]
						+ E[j].c > dist[E[j].t]))) {
					dist[E[j].t] = dist[E[j].f] + E[j].c;
					prv[E[j].t] = j;
					Flow[E[j].t] = min(Flow[E[j].f], int(E[j].cap));
					relax = true;
				}
			}

		}
		if (!relax) {
			break;
		}

	}
	return (Flow[d] ? dist[d] : -1);
}
void removePath(int p) {
	while (p > -1) {
		E[p].cap = 0;

		if (p % 2 == 0)
			E[p + 1].cap = 1;
		else
			E[p - 1].cap = 1;

		p = prv[E[p].f];
	}
}
int maxFlow(int s, int d, bool Min) {
	int total = 0, res;

	while (1) {
		res = bellman(s, d, Min);
		if (res == -1)
			return total;
		total += res;
		removePath(prv[d]);
	}
	return total;
}

int main() {

	int tst;
	scanf("%d", &tst);
	int c1, c2;
	while (tst--) {
		E.clear();
		scanf("%d%d", &c1, &c2);
		int f, t, c, n = c1 + c2;

		foe(i,1,n) {
			edge e1 = { 0, i, 0, 1 }, e2 = { i, 0, 0, 0 };
			E.push_back(e1), E.push_back(e2);
		}

		while (scanf("%d%d%d", &f, &t, &c) != -1 && (f || t || c)) {

			edge e1 = { f, t + n, c, 1 }, e2 = { t + n, f, -c, 0 };
			E.push_back(e1), E.push_back(e2);
		}

		foe(i,n+1,n+n) {
			edge e2 = { n + n + 1, i, 0, 0 }, e1 = { i, n + n + 1, 0, 1 };
			E.push_back(e1), E.push_back(e2);
		}

		printf("%d\n", maxFlow(0, n + n + 1, 0));
	}
	return 0;
}
