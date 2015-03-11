#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <ctype.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

string graph[102];
bool vis[102][102];
int sz;

int di[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dj[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int DFS(int si, int sj) {

	int res = 1;
	fo(d,8) {
		int newr = si + di[d];
		int newc = sj + dj[d];

		if (newr < 0 || newc < 0 || newr >= sz || newc >= graph[newr].size())
			continue;

		if (vis[newr][newc] || graph[newr][newc] != 'W')
			continue;

		vis[newr][newc] = 1;
		res += DFS(newr, newc);
	}
	return res;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int t;
	cin >> t;
	string str;
	getline(cin, str);
	getline(cin, str);
	string e = "";

	while (t--) {
		cout << e, e = "\n";
		sz = 0;
		while (getline(cin, str)) {
			if (str == "")
				break;
			else if (isalpha(str[0]))
				graph[sz++] = str;

			else {
				int x,y;
				sscanf(str.c_str(),"%d%d",&x,&y);
				x--,y--;

				vis[x][y] = 1;
				cout << DFS(x, y) << endl;
				memset(vis, 0, sizeof vis);
			}
		}
	}

	return 0;
}
