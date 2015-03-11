#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>

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

int n, e;
vector<vector<int> > adjlst(10010);
bool vis[10010];

bool DFS(int cur, int prev) {

	rep(i,sz(adjlst[cur])) {
		int nxt = adjlst[cur][i];

		if (nxt == prev)
			continue;

		if (vis[nxt])
			return false;

		vis[cur] = 1;
		if (DFS(nxt, cur) == 0)
			return 0;

	}

	return 1;
}
int main() {

	int s, d;
	scanf("%d%d", &n, &e);
	set<pii> edges;

	rep(i,e) {
		scanf("%d%d", &s, &d);
		if(s==d){
			printf("NO\n");
			return 0;
		}
		if (s > d)
			swap(s, d);

		if (edges.find(mp(s,d)) == edges.end()) {
			edges.insert(mp(s,d));
			adjlst[s].push_back(d);
			adjlst[d].push_back(s);
		}

	}

	int leaf = -1;
	repe(i,1,n) {
		if (n == 1) {
			if (sz(adjlst[i]) == 0) {
				leaf = i;
				break;
			}

			printf("NO\n");
			return 0;
		}

		else if (sz(adjlst[i]) == 0) {
			printf("NO\n");
			return 0;
		}

		else if (sz(adjlst[i]) == 1) {
			leaf = i;
		}
	}

	if (n != sz(edges) + 1 || leaf == -1 || DFS(leaf, -1) == 0)
		printf("NO\n");

	else
		printf("YES\n");

	return 0;
}

