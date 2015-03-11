#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define pb(n)       push_back(n)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;

vi res;

void dfs(vvi& graph, int ind) {

	int sz = graph[ind].size() + 1;
	while (sz--) {
		int el = graph[ind][0];

		if (el == 0) {
			res.pb(ind);
			graph[ind][0] = -1;
			return;
		}

		if (el == -1)
			return;

		graph[ind].erase(graph[ind].begin());

		dfs(graph, el);
	}

}

int main() {

	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			return 0;

		vvi graph(n + 1);

		int n1, n2;

		while (m--) {
			cin >> n1 >> n2;
			graph[n1].pb(n2);
		}

		for (int i = 1; i <= n; i++)
			graph[i].pb(0);

		for (int i = 1; i <= n; i++) {
			dfs(graph, i);
		}

		reverse(res.begin(), res.end());

		int sz = res.size();

		fo(i,sz) {
			cout << res[i];
			if (i + 1 < sz)
				cout << " ";
		}

		cout << endl;
		res.erase(res.begin(), res.end());
	}
	return 0;
}
