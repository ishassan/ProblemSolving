/*
 ID: fci_isl1
 LANG: C++
 TASK: holstein
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int nvit, nfeed, minLen = 2000000000;
string minPath;

int graph[16][26];

bool isfinish(vector<int>& vit) {

	for (int i = 0; i < nvit; i++)
		if (vit[i] > 0)
			return 0;

	return 1;
}

void DFS(vector<int> vit, vector<bool> vis, string path, int len, int step) {
	if (len == nfeed || isfinish(vit)) {
		if (len < minLen)
			minLen = len, minPath = path;
		return;
	}

	vis[step] = 1;
	stringstream ss;
	ss << step + 1;
	path += ss.str()+" ";
	len++;

	for (int i = 0; i < nvit; i++){
		vit[i] = vit[i] - graph[step][i];
	}
	if (isfinish(vit)) {
		if (len < minLen)
			minLen = len, minPath = path;
		return;
	}

	for (int i = step+1; i < nfeed; i++)
		if (!vis[i])
			DFS(vit, vis, path, len, i);
}
int main() {
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	cin>>nvit;

	vector<int> vit(nvit);

	for (int i = 0; i < nvit; i++)
		cin>>vit[i];

	cin>>nfeed;
	vector<bool> vis(nfeed, 0);

	for (int i = 0; i < nfeed; i++)
		for (int j = 0; j < nvit; j++)
			cin>>graph[i][j];

	for (int i = 0; i < nfeed; i++)
		DFS(vit, vis, "", 0, i);

	cout << minLen << " ";
	int n = minPath.size()-1;

	for (int i = 0; i < n; i++)
		cout << minPath[i];
	cout << endl;

	return 0;
}
