#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef vector<string> vs;
map<string, bool> vis;

string bfs(string from, string to, map<string, vs>& graph) {

	queue<pair<string, string> > q;
	q.push(make_pair(from, ""));
	vis[from] = 1;

	while (!q.empty()) {
		string cur = q.front().first;
		string path = q.front().second;
		q.pop();

		if (cur == to)
			return path + cur;

		for (int i = 0; i < graph[cur].size(); i++) {
			string x = graph[cur][i];

			if (!vis[x]) {
				vis[x] = 1;
				q.push(make_pair(x, path + cur));
			}
		}
	}
	return "No route";
}
int main() {

	int n;
	bool start = false;
	while (cin >> n) {
		if (start)
			cout << endl;
		start = 1;

		map<string, vs> g;
		string src, dis;

		for (int i = 0; i < n; i++) {
			cin >> src >> dis;
			g[src].push_back(dis);
			g[dis].push_back(src);
		}
		cin >> src >> dis;

		vis.clear();
		string res = bfs(src, dis, g);

		if (res == "No route") {
			cout << res<<endl;
			continue;
		}

		while (res.size() >2) {
			cout << res[0] << res[1] << " " << res[2] << res[3]<<endl;
			res.erase(0,2);
		}
	}
	return 0;
}
