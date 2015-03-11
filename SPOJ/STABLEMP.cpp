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
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define vit list<pair<int, pii> >::iterator
typedef long long ll;
using namespace std;

int n;

vector<queue<int> > men;
int women[505][505];
int husband[505], wife[505];
queue<int> unMatchedMen;

int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		men.clear();
		mem(women,0);
		mem(husband,0), mem(wife,0);
		scanf("%d", &n);
		men.resize(n + 5);

		rep(i,n) {
			int m, w;
			scanf("%d", &w);
			rep(j,n) {
				scanf("%d", &m);
				women[w][m] = n - j;
			}
		}

		rep(i,n) {
			int m, w;
			scanf("%d", &m);
			unMatchedMen.push(m);
			rep(j,n) {
				scanf("%d", &w);
				men[m].push(w);
			}
		}

		while (unMatchedMen.size()) {
			int m = unMatchedMen.front();
			unMatchedMen.pop();
			while (men[m].size()) {
				int w = men[m].front();
				men[m].pop();
				if (!husband[w]) {
					husband[w] = m;
					wife[m] = w;
					break;
				} else if (women[w][m] > women[w][husband[w]]) {
					unMatchedMen.push(husband[w]);
					wife[husband[w]] = 0;
					wife[m] = w;
					husband[w] = m;
					break;
				}
			}
		}

		repe(i,1,n)
			if (wife[i])
				printf("%d %d\n", i, wife[i]);

	}

	return 0;
}

