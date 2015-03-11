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

const int MAX = 1003;

vector<vector<int> > adjlst;
vector<pii> del;
int parent[MAX], rank[MAX];

int find(int e) {
	if (parent[e] == e)
		return e;
	return parent[e] = find(parent[e]);
}

bool join(int e1, int e2) {
	int p1 = find(e1);
	int p2 = find(e2);

	if (p1 == p2)
		return 0;

	if (rank[p1] == rank[p2])
		rank[p1]++;

	else if (rank[p2] > rank[p1])
		swap(p1, p2);

	parent[p2] = p1;
	return 1;
}

int main() {

	memset(rank, 0, sizeof rank);

	int n, a, b;
	scanf("%d", &n);
	adjlst.resize(n + 3);

	foe(i,1,n)
		parent[i] = i;

	fo(i,n-1) {
		scanf("%d%d", &a, &b);
		adjlst[a].push_back(b);
	}

	foe(i,1,n)
		fo(j,adjlst[i].size())
			if (!join(i, adjlst[i][j]))
				del.push_back(mp(i,adjlst[i][j]));

	printf("%d\n", del.size());

	foe(i,1,n)
		foe(j,i+1,n)
			if (join(i, j)) {
				pii p = del.front();
				printf("%d %d %d %d\n", p.first, p.second, i, j);
				del.erase(del.begin());
			}

	return 0;
}

