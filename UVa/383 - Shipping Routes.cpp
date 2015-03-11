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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

map<string, vector<string> > graph;
map<string, bool> vis;

int BFS(string src, string dest) {
	queue<string> q;
	q.push(src);
	int lvl = 0;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			src = q.front();
			q.pop();

			if (src == dest)
				return lvl;

			int sz = graph[src].size();
			fo(i,sz) {
				string d = graph[src][i];
				if (vis.find(d) == vis.end())
					q.push(d), vis[d] = 1;
			}
		}
		lvl++;
	}
	return -1;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	cout << "SHIPPING ROUTES OUTPUT\n\n";

	int tst;
	cin >> tst;
	foe(t,1,tst) {
		int n, l, p, cst;
		string s1, s2;
		cin >> n >> l >> p;

		graph.clear();
		fo(i,n)
			cin >> s1;

		fo(i,l) {
			cin >> s1 >> s2;
			graph[s1].push_back(s2);
			graph[s2].push_back(s1);
		}

		cout << "DATA SET  " << t << "\n\n";

		fo(i,p) {
			cin >> cst >> s1 >> s2;
			vis.clear();
			int b = BFS(s1, s2);
			if (b == -1)
				cout << "NO SHIPMENT POSSIBLE\n";
			else
				cout << "$" << b * cst * 100 << endl;
		}
		cout << endl;
	}

	cout << "END OF OUTPUT\n";
	return 0;
}

