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
map<string, int> Map;
vector<vector<pair<int, int> > > adjlst;

int DijHeap(int src, int dest) {
	priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int,
			int> > > q;

	q.push(mp(0,src));
	int dist[10002] = { 0 };
	rep(i,n)
		dist[i] = 1 << 27;
	dist[src] = 0;

	while (q.size()) {
		int cur = q.top().second;
		q.pop();

		if (cur == dest)
			return dist[dest];
		repi(it, adjlst[cur]) {
			if (dist[cur] + it->first < dist[it->second]) {
				dist[it->second] = dist[cur] + it->first;
				q.push(mp(dist[it->second], it->second));
			}
		}
	}
	return 1 << 27;
}

int main() {

	int tst;
	scanf("%d", &tst);
	char* end="";
	while (tst--) {
		Map.clear();
		adjlst.clear();
		scanf("%d", &n);
		string name;
		adjlst.resize(n);
		int g;
		rep(i,n) {
			cin >> name;
			Map[name] = i;
			scanf("%d", &g);
			int to, cst;
			while (g--) {
				scanf("%d%d", &to, &cst), --to;
				adjlst[i].push_back(mp(cst,to));
			}
		}

		int num;
		scanf("%d", &num);
		string a, b;
		while (num--) {
			cin >> a >> b;
			int src = Map[a], dest = Map[b];
			printf("%d\n", DijHeap(src, dest));
		}


	}
}
