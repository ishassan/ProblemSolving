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
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int n;
vi adjlst[10003];
bool vis[10003];

pii BFS(int start) {
	queue<int> q;
	q.push(start);
	vis[start] = true;

	int last = start;
	int cst = 0;
	while (q.size()) {
		int size = q.size();
		while (size--) {
			start = q.front();
			q.pop();

			last = start;
			rep(i,sz(adjlst[start])) {
				if (!vis[adjlst[start][i]])
					q.push(adjlst[start][i]), vis[adjlst[start][i]]=true;
			}
		}
		++cst;
	}

	return mp(last,cst-1);
}
int main() {
	scanf("%d", &n);

	reps(i,1,n) {
		int a, b;
		scanf("%d%d", &a, &b);
		adjlst[a].push_back(b);
		adjlst[b].push_back(a);
	}
	pii p = BFS(1);
	memset(vis, 0, sizeof(vis));

	p = BFS(p.first);
	printf("%d\n", p.second);

	return 0;
}
