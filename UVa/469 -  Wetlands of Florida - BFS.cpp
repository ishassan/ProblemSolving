#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <ctype.h>
#include <queue>

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

int BFS(int si, int sj) {
	queue<pii> q;
	q.push(mp(si,sj));
	int res=1;
	while(!q.empty()){
		si = q.front().first;
		sj = q.front().second;
		q.pop();

		fo(d,8){
			int newr = si +di[d];
			int newc = sj +dj[d];

			if(newr < 0 || newc<0 || newr>=sz || newc>=graph[newr].size())
				continue;

			if(vis[newr][newc] || graph[newr][newc]=='L')
				continue;

			vis[newr][newc]=1;
			q.push(mp(newr,newc));
			res++;
		}
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
				cout << BFS(x, y) << endl;
				memset(vis, 0, sizeof vis);
			}
		}
	}

	return 0;
}
