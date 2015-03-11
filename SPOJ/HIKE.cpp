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

int n;
char color[52][52];
unsigned int dist[52][52][52];
struct state {
	int i1, i2, i3;
};
state tostate(int q1, int q2, int q3) {
	state s = { q1, q2, q3 };
	return s;
}

int BFS(int q1, int q2, int q3) {
	queue<state> q;
	state s = { q1, q2, q3 };
	q.push(s);
	dist[q1][q2][q3] = 0;
	while (q.size()) {
		s = q.front();
		q.pop();

		if (s.i1 == s.i2 && s.i2 == s.i3)
			return dist[s.i1][s.i2][s.i3];

		int d = dist[s.i1][s.i2][s.i3] + 1;
		rep(i,n) {
			if (color[s.i1][i] == color[s.i2][s.i3] && d < dist[i][s.i2][s.i3])
				dist[i][s.i2][s.i3] = d, q.push(tostate(i, s.i2, s.i3));

			if (color[s.i2][i] == color[s.i1][s.i3] && d < dist[s.i1][i][s.i3])
				dist[s.i1][i][s.i3] = d, q.push(tostate(s.i1, i, s.i3));

			if (color[s.i3][i] == color[s.i1][s.i2] && d < dist[s.i1][s.i2][i])
				dist[s.i1][s.i2][i] = d, q.push(tostate(s.i1, s.i2, i));
		}

	}
	return -1;
}
int main() {

	int q1, q2, q3;
	while (scanf("%d", &n) && n) {
		scanf("%d%d%d", &q1, &q2, &q3);
		--q1, --q2, --q3;
		rep(i,n)
			rep(j,n)
				scanf(" %c", &color[i][j]);

		mem(dist,-1);
		int res = BFS(q1, q2, q3);
		if (res == -1)
			printf("impossible\n");
		else
			printf("%d\n", res);
	}
	return 0;
}
