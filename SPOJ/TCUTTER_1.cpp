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
#include <hash_map>

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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

int n;
hash_map<int, int> Map;
vector<pair<pii, pii> > v;
set<int> st;

int mat[1000][1000];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool border[1000][1000];

int xmx, ymx;

void floodfill(int i, int j, bool allowneg) {
	queue<pii> q;
	q.push(mp(i,j));
	while (q.size()) {
		i = q.front().first;
		j = q.front().second;

		q.pop();
		rep(d,4) {
			int ni = i + di[d];
			int nj = j + dj[d];
			if (ni < 0 || nj < 0 || nj > xmx || ni > ymx || mat[ni][nj] == 1)
				continue;

			if (mat[ni][nj] == -1) {
				if (!allowneg) {
					border[ni][nj] = 1;
					continue;
				}
				else if(border[ni][nj])
					continue;
			}
			mat[ni][nj] = 1;
			q.push(mp(ni, nj));
		}
	}
}
int main() {

	while (scanf("%d", &n) && n) {
		int x1, y1, x2, y2;
		st.clear(), v.clear(), Map.clear();
		v.resize(n);
		mem(mat,0), mem(border,0);
		xmx = 0, ymx = 0;
		rep(i,n) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			v[i] = mp(mp(x1,y1) , mp(x2,y2));
			st.insert(x1);
			st.insert(x2);
			st.insert(y1);
			st.insert(y2);
		}
		int cnt = 1;
		repi(it, st) {
			Map[*it] = cnt;
			cnt += 2;
		}

		rep(i,n) {

			int x1 = Map[v[i].first.first], y1 = Map[v[i].first.second];
			int x2 = Map[v[i].second.first], y2 = Map[v[i].second.second];

			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);

			xmx = max(xmx, x2), ymx = max(ymx, y2);
			if (x1 == x2) {
				repe(j,y1,y2)
					mat[j][x1] = -1;
			}

			else {
				repe(j,x1,x2)
					mat[y1][j] = -1;
			}
		}

		xmx += 5, ymx += 5;
		mat[0][0] = 1;
		floodfill(0, 0, 0);
		int res = 0;
		rep(i,ymx)
			rep(j,xmx)
				if (mat[i][j] == 0) {
					++res;
					floodfill(i, j, 1);
				}
		printf("%d\n", res);

	}

	return 0;
}
