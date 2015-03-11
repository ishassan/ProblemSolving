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
typedef long long ll;
using namespace std;

map<string, vector<string> > m;
map<string, vector<string> > onit;
set<string> st, found;
int main() {

	//freopen("in.in", "r", stdin);
	string src;
	while (cin >> src) {
		st.insert(src);
		string dist;
		while (cin >> dist) {
			if (dist == "0")
				break;
			m[src].push_back(dist);
			onit[dist].push_back(src);
		}
	}

	for (set<string>::iterator it = st.begin(); it != st.end(); it++) {
		if (m[*it].empty())
			found.insert(*it);
	}

	bool change = 1;
	while (change) {
		change = 0;
		for (set<string>::iterator it = found.begin(); it != found.end(); it++)
			for (int i = 0; i < onit[*it].size(); i++) {
				string dep = onit[*it][i];
				if (found.find(dep) != found.end())
					continue;
				bool s = 1;
				for (int j = 0; j < m[dep].size(); j++) {
					if (found.find(m[dep][j]) == found.end()) {
						s = 0;
						break;
					}
				}
				if (s)
					found.insert(dep), change = 1;

			}
	}
	cout << found.size() << endl;
	return 0;
}
