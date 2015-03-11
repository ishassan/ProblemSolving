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

int r, c;
char graph[1003][1003];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

pair<int, pii> BFS(int i, int j) {
	bool vis[1003][1003] = { {0} };
	queue<pair<int, pii> > q;
	q.push(mp(0,mp(i,j)));
	vis[i][j] = 1;
	pair<int, pii> mx = q.front();
	while (q.size()) {
		int s = q.front().first;
		i = q.front().second.first;
		j = q.front().second.second;
		if (s > mx.first)
			mx = q.front();
		q.pop();

		rep(d,4) {
			int newi = i + di[d];
			int newj = j + dj[d];
			if (newi < 0 || newj < 0 || newi >= r || newj >= c
					|| vis[newi][newj] || graph[newi][newj]=='#')
				continue;
			vis[newi][newj]=1;
			q.push(mp(s+1,mp(newi,newj)));
		}
	}

	return mx;
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d", &c, &r);
		rep(i,r)
			scanf("%s", graph[i]);

		pair<int, pii> ret,cur;
		rep(i,r)
			rep(j,c)
				if (graph[i][j] == '.') {
					ret = BFS(i, j), cur = ret;
					while (1) {
						cur = BFS(cur.second.first, cur.second.second);
						if (cur.first > ret.first)
							ret = cur;
						else
							goto end;
					}

				}
		end: ;
		printf("Maximum rope length is %d.\n", ret.first);

	}
	return 0;
}
