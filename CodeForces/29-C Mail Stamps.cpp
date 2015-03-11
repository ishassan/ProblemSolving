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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int path[100010];
int idxp = 0;

int main() {
	int n, a, b;
	map<int, vi> m;
	map<int,bool> vis;

	scanf("%d", &n);
	set<int> in;
	fo(i,n) {
		scanf("%d%d", &a, &b);
		in.insert(a), in.insert(b);
		m[a].push_back(b), m[b].push_back(a);
	}

	int src;
	for (set<int>::iterator it = in.begin(); it != in.end(); it++) {
		if (m[*it].size() == 1) {
			src = *it;
			break;
		}
	}

	path[idxp++] = src;
	vis[src]=1;
	fo(i,m[src].size()) {
		int d = m[src][i];
		if (!vis[d]) {
			path[idxp++] = d;
			vis[d]=1;
			src = d;
			i = -1;
		}
	}

	fo(i,idxp)
		printf("%d ", path[i]);
	return 0;
}
