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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

const int SIZE = 55;
struct DisjointSets {
	int parent[SIZE], rank[SIZE], componentsCnt;
	DisjointSets(int n) {
		memset(rank, 0, sizeof rank);
		for (int i = 0; i < n; i++)
			parent[i] = i;
		componentsCnt = n;
	}
	int find(int e) {
		return parent[e] == e ? e : parent[e] = find(parent[e]);
	}
	bool join(int e1, int e2) {
		int p1 = find(e1), p2 = find(e2);
		if (p1 == p2)
			return 0;
		if (rank[p1] == rank[p2])
			rank[p1]++;
		if (rank[p2] > rank[p1])
			swap(p1, p2);
		parent[p2] = p1;
		componentsCnt--; // new components get merged
		return 1;
	}
};

int n;
pair<pii, int> arr[55];
double graph[55][55];
bool vis[55];
double t[55];
vector<vi> mst;

double cost(int i, int j) {
	return hypot(arr[i].first.first - arr[j].first.first, arr[i].first.second
			- arr[j].first.second);
}

void floodfill(int idx, double cst) {
	if (vis[idx])
		return;
	vis[idx] = 1;
	t[idx] = cst;
	rep(i,sz(mst[idx]))
		floodfill(mst[idx][i], max(cst, graph[idx][mst[idx][i]]));
}
int main() {

	int tst = 1;
	while (scanf("%d", &n) && n) {
		mst.clear();
		mst.resize(n);
		mem(vis,0);
		rep(i,n)
			scanf("%d%d%d", &arr[i].first.first, &arr[i].first.second,
					&arr[i].second);

		vector<pair<double, pii> > v;
		rep(i,n)
			reps(j,i+1,n) {
				graph[i][j] = graph[j][i] = cost(i, j);
				v.push_back(mp(graph[i][j], mp(i,j)));
			}
		sort(all(v));
		DisjointSets s(n);
		rep(i,sz(v)) {
			if (s.join(v[i].second.first, v[i].second.second)) {
				mst[v[i].second.first].push_back(v[i].second.second);
				mst[v[i].second.second].push_back(v[i].second.first);
			}
		}
		floodfill(0, 0);
		double r = 0;
		int p = 0;
		rep(i,n) {
			r += t[i] * arr[i].second;
			p += arr[i].second;
		}

		printf("Island Group: %d Average %.2lf\n\n", tst++, r / p);

	}

	return 0;
}
