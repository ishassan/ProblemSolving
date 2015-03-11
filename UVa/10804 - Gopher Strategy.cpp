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
#define pdd pair<double,double>
typedef long long ll;
using namespace std;

int n, m, k;
const int MAX = 150;
pdd gopher[MAX], holes[MAX];

double dstnce[MAX][MAX];

vector<int> adjlst[MAX];
int N, man[MAX];
int M, woman[MAX];
bool visited[MAX];

bool match(int manIndex) {
	for (int i = 0; i < adjlst[manIndex].size(); i++) {
		int curwoman = adjlst[manIndex][i];
		if (visited[curwoman])
			continue;
		visited[curwoman] = true;
		if (woman[curwoman] == -1 || match(woman[curwoman])) {
			man[manIndex] = curwoman;
			woman[curwoman] = manIndex;
			return true;
		}
	}
	return false;
}
int maxMatch() {
	int cnt = 0;
	memset(man, -1, sizeof man);
	memset(woman, -1, sizeof woman);
	for (int i = 0; i < N; i++)
		if (man[i] == -1) {
			memset(visited, 0, sizeof visited);
			if (match(i))
				cnt++;
		}
	return cnt;
}

void build(double t) {

	fo(i,N+2)
		adjlst[i].clear();

	fo(i,n)
		fo(j,m)
			if (dstnce[i][j] < t)
				adjlst[i].push_back(j);

}
int main() {

	int tst;
	scanf("%d", &tst);
	foe(tt,1,tst) {
		scanf("%d%d%d", &n, &m, &k);
		double s = 0.0, e = 0.0;
		N = n;
		fo(i,n)
			scanf("%lf%lf", &gopher[i].first, &gopher[i].second);

		fo(i,m)
			scanf("%lf%lf", &holes[i].first, &holes[i].second);

		fo(i,n)
			fo(j,m) {
				dstnce[i][j] = hypot(gopher[i].first - holes[j].first,
						gopher[i].second - holes[j].second);

				e = max(e, dstnce[i][j]);
			}

		int res = 0;
		double lst = 0;
		while (fabs(s - e) > 1e-9) {
			double mid = (s + e) / 2.0;
			build(mid);
			res = maxMatch();

			if (res >= n - k)
				lst = e = mid;

			else
				s = mid;
		}

		printf("Case #%d:\n", tt);
		build(lst);
		res = maxMatch();
		if (res >= n - k)
			printf("%.3lf\n\n", lst);
		else
			printf("Too bad.\n\n");
	}
	return 0;
}
