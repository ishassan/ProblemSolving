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
#include <hash_map>

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
using namespace __gnu_cxx;

const int SIZE = 10005;
struct DisjointSet {
	int nComp;
	int par[SIZE], rank[SIZE];
	DisjointSet(int n) {
		nComp = n;
		rep(i,n)
			par[i] = i, rank[i] = 0;
	}

	int find(int n) {
		if (par[n] == n)
			return n;
		return par[n] = find(par[n]);
	}

	bool join(int s1, int s2) {
		s1 = find(s1);
		s2 = find(s2);

		if (s1 == s2)
			return false;

		if (rank[s1] < rank[s2])
			par[s1] = s2;
		else if (rank[s1] > rank[s2])
			par[s2] = s1;
		else
			par[s1] = s2, rank[s2]++;

		--nComp;
		return 1;
	}
};

struct edge {
	int src, dest, cst;
	edge(int s, int d, int c) {
		src = s, dest = d, cst = c;
	}

	bool operator<(const edge& e) const {
		if (cst < e.cst)
			return 1;
		if (cst > e.cst)
			return 0;
		if (src < e.src)
			return 1;
		if (src > e.src)
			return 0;
		return dest < e.dest;
	}
};
int n, m, port;
vector<edge> edges;
int main() {

	int tst;
	scanf("%d", &tst);
	repe(t,1,tst) {
		scanf("%d%d%d", &n, &m, &port);
		edges.clear();
		int src, dest, cst;
		rep(i,m) {
			scanf("%d%d%d", &src, &dest, &cst);
			edges.push_back(edge(src-1, dest-1, cst));
			edges.push_back(edge(dest-1, src-1, cst));
		}

		DisjointSet dis(n);
		ll res = ((ll) n) * port;
		ll val = res;
		int nair = n;
		sort(all(edges));
		rep(i,edges.size()) {
			if (dis.join(edges[i].src, edges[i].dest)) {
				val += edges[i].cst - port;
				if (res > val) {
					nair = dis.nComp;
					res = val;
				}

			}
		}

		cout << "Case #" << t << ": " << res << " " << nair << endl;
	}

	return 0;
}
