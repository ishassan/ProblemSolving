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
#define vit list<pair<int, pii> >::iterator
typedef long long ll;
using namespace std;

vector<vector<pii> > nodes;
vi path;
bool vis[2000];
int start;

void DFS(int idx) {

	repi(it, nodes[idx]) {
		if (vis[it->first])
			continue;

		vis[it->first] = 1;
		DFS(it->second);
		path.push_back(it->first);
	}
}


int main() {

//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);

	int a, b, c;
	while (1) {
		int degree[2000] = { 0 };
		bool end = 1;
		path.clear();
		nodes.clear();
		nodes.resize(2000);
		start = -1;
		mem(vis,0);

		while (scanf("%d%d", &a, &b) && (a || b)) {
			scanf("%d", &c);
			nodes[a].push_back(mp(c,b));
			nodes[b].push_back(mp(c,a));
			++degree[a], ++degree[b];
			end = 0;
			if (start == -1)
				start = min(a, b);
		}
		if (end)
			break;

		end = 0;
		rep(i,2000)
			if (degree[i] % 2) {
				end = 1;
				break;
			}

		if (end) {
			printf("Round trip does not exist.\n\n");
			continue;
		}

		rep(i,2000)
			sort(all(nodes[i]));

		DFS(start);

		reverse(all(path));
		rep(i,sz(path)) {
			printf("%d", path[i]);
			if (i + 1 == sz(path))
				printf("\n");
			else
				printf(" ");
		}

		printf("\n");
	}
	return 0;
}

