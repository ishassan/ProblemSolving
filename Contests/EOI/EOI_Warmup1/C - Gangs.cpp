#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>
#include <cmath>
#include <queue>
#include <set>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int n, s, start, end;
vector<pair<int, int> > graph[10005];
int dist[10005];


int BFJ() {

	fill(dist, dist + 10005, 1e9);
	dist[start] = 0;

	priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int,
			int> > > q;
	q.push(mp(0,start));
	while (!q.empty()) {
		start = q.top().second;
		int cost = q.top().first;
		q.pop();

		fo(i,(int)graph[start].size()) {
			int node = graph[start][i].second;
			if (dist[node] > cost + graph[start][i].first) {
				dist[node] = cost + graph[start][i].first;
				q.push(mp(dist[node] , node));
			}
		}
	}
	return dist[end] ;

}
int main() {

	cin >> n >> s >> start >> end;

	int a, b;
	int c, d;
	fo(i,s) {
		cin >> a >> b >> c >> d;
		graph[a].push_back(mp(10*(c+d),b));
		graph[b].push_back(mp(10*(c+d),a));
	}

	cout << BFJ() << endl;
	return 0;
}

