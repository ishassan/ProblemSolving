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

const int SIZE = 60;
int n;
int graph[SIZE][SIZE];
int degree[SIZE];
int nedge[SIZE][SIZE];
vi path;
void DFS(int idx) {
	repe(i,1,50)
		if (graph[idx][i] && nedge[idx][i]) {
			--nedge[idx][i], --nedge[i][idx];
			DFS(i);
			path.push_back(i);
		}
}
int main() {

	int tst;
	scanf("%d", &tst);
	string endl = "";
	repe(t,1,tst) {
		cout << endl, endl = "\n";
		mem(graph,0);
		mem(degree,0);
		mem(nedge,0);
		path.clear();
		scanf("%d", &n);

		int a, b;
		rep(i,n) {
			scanf("%d%d", &a, &b);
			++graph[a][b], ++graph[b][a];
			++nedge[a][b], ++nedge[b][a];
			++degree[a], ++degree[b];
		}

		bool valid = 1;
		repe(i,1,50)
			if (degree[i] % 2) {
				valid = 0;
				break;
			}

		printf("Case #%d\n", t);
		if (!valid) {
			printf("some beads may be lost\n");
			continue;
		}

		DFS(a);
		path.push_back(a);

		valid = 1;
		repe(i,1,50)
			repe(j,1,50)
				if (graph[i][j] && nedge[i][j]) {
					valid = 0;
					break;
				}

		if (!valid) {
			printf("some beads may be lost\n");
			continue;
		}

		reverse(all(path));
		rep(i,sz(path)-1)
			printf("%d %d\n", path[i], path[i + 1]);

	}
	return 0;
}
