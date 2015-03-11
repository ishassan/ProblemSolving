/*
 * H - wordLadder.cpp
 *
 *  Created on: Oct 15, 2010
 *      Author: Administrator
 */

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

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,s,m) for(int i=s;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define PI = (2.0 * acos(0.0));
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define OO ((int)1e9)

int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[] = { -1, 0, 1, 0, 1, -1, -1, 1 };

bool vis[501];
int dist[501][501];
map<string, int> m;
vector<vector<int> > adjList;
vector<string> v;

void createList() {
	for (int it = 0; it < (int) v.size(); it++) {
		string word = v[it];
		for (int i = 0; i < (int) word.size(); i++) {
			for (char j = 'a'; j <= 'z'; j++) {
				if (word[i] != j) {
					string w1 = word.substr(0, i) + j + word.substr(i);
					string w2 = word;
					w2[i] = j;
					if (m.find(w1) != m.end())
						adjList[it].push_back(m[w1]);
					if (m.find(w2) != m.end())
						adjList[it].push_back(m[w2]);
				}
			}
			string w3 = word.substr(0, i) + word.substr(i + 1);
			if (m.find(w3) != m.end())
				adjList[it].push_back(m[w3]);

		}
		for (char j = 'a'; j <= 'z'; j++) {
			string w1 = word + j;
			if (m.find(w1) != m.end())
				adjList[it].push_back(m[w1]);

		}
	}
}

int bfs() {
	memset(dist,0,sizeof(dist));
	for (int k = 0; k < v.size(); k++) {
		queue<int> q;
		memset(vis, 0, sizeof(vis));
		q.push(k);
		vis[k] = 1;
		int st = 1;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int cur = q.front();
				dist[k][cur] = st;

				q.pop();
				for (int j = 0; j < (int) adjList[cur].size(); j++) {

					if (!vis[adjList[cur][j]]) {
						vis[adjList[cur][j]] = 1;
						q.push(adjList[cur][j]);
					}
				}
			}
			st++;
		}
	}
	int res = 0;
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v.size(); j++)
			res = max(res, dist[i][j]);
	return res;
}

int main() {
	freopen("H.in","r",stdin);

	int n;
	string w;
	while (cin >> n && n) {
		v.clear();
		m.clear();
		for (int i = 0; i < n; i++) {
			cin >> w;
			v.push_back(w);
			m[w] = i;
		}
		adjList.clear();
		adjList.resize(n);

		createList();
		cout << bfs() << endl;
	}
	return 0;
}



