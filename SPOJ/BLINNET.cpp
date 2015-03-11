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

int n;
int parent[10000], rank[10000];

struct edge {
	int from, to, cst;
	edge(int f, int t, int c) {
		from = f, to = t, cst = c;
	}
};

bool cmp(edge e1, edge e2) {
	if (e1.cst < e2.cst)
		return 1;
	if (e1.cst > e2.cst)
		return 0;
	if (e1.from < e2.from)
		return 1;
	if (e1.from > e2.from)
		return 0;
	return e1.to < e2.to;
}
vector<edge> edges;
void init() {
	edges.clear();
	rep(i,n)
		parent[i] = i, rank[i] = 1;
}

int find(int node) {
	if (parent[node] == node)
		return node;
	return parent[node] = find(parent[node]);
}

bool join(int n1, int n2) {
	n1 = find(n1), n2 = find(n2);
	if (n1 == n2)
		return 0;
	if (rank[n1] > rank[n2])
		parent[n2] = n1;
	else if (rank[n1] < rank[n2])
		parent[n1] = n2;
	else
		parent[n1] = n2, ++rank[n2];
	return 1;
}

int main() {

	int tst, m, a, b;
	char str[20];
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d", &n);
		init();
		rep(i,n) {
			scanf("%s", str);
			scanf("%d", &m);
			while (m--) {
				scanf("%d%d", &a, &b);
				edges.push_back(edge(i, a - 1, b));
			}
		}
		int res=0;
		sort(all(edges),cmp) ;
		rep(i,sz(edges)){
			if(join(edges[i].from, edges[i].to))
				res += edges[i].cst;
		}
		printf("%d\n",res);

	}

	return 0;
}
