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

map<string, vector<string> > m;
map<string, string> par;
map<string, bool> vis;
vector<string> path;
string src, dest;

void print() {
	while (dest != "0") {
		path.push_back(dest);
		dest = par[dest];
	}
}
bool BFS() {
	queue<string> q;
	q.push(src);
	par[src] = "0";
	while (!q.empty()) {
		src = q.front();
		q.pop();

		if (src == dest) {
			print();
			return 1;
		}

		int sz = m[src].size();
		fo(i,sz) {
			if (vis.find(m[src][i]) == vis.end()) {
				vis[m[src][i]] = 1;
				par[m[src][i]] = src;
				q.push(m[src][i]);
			}
		}

	}
	return 0;
}
int main() {
	//freopen("in.in","r",stdin);
	//freopen("out.out", "w", stdout);

	int n;
	string end = "";
	while (cin >> n) {
		cout << end;
		end = "\n";
		m.clear(), par.clear(), vis.clear(), path.clear();
		fo(i,n) {
			cin >> src >> dest;
			m[src].push_back(dest);
			m[dest].push_back(src);
		}
		cin >> src >> dest;

		if (src == dest) {
			cout << src << " " << dest << endl;
			continue;
		}
		vis[src] = 1;
		bool r = BFS();
		if (!r) {
			cout << "No route\n";
			continue;
		}

		int sz = path.size();
		for (int i = sz - 1; i > 1; i--)
			cout << path[i] << " " << path[i - 1] << endl;

		if (sz > 1)
			cout << path[1] << " " << path[0] << endl;
	}

	return 0;
}

