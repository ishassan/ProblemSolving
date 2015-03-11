#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>
typedef long long ll;

using namespace std;

int lvl = -1;
vector<ll> graph[17];

void getInput(string str) {
	int sz = str.size();
	for (int i = 0; i < sz; i++) {
		if (str[i] == '[')
			lvl++;

		else if (str[i] == ']')
			lvl--;

		else if (isdigit(str[i])) {
			ll res = 0;

			while (isdigit(str[i])) {
				res *= 10;
				res += str[i] - '0';
				i++;
			}

			graph[lvl].push_back(res);
			i--;
		}
	}
}
int main() {

	map<ll, ll> cnt;
	string s;
	getline(cin, s);

	if (isdigit(s[0])) {
		cout << 0 << endl;
		return 0;
	}

	getInput(s);
	ll mx = -1, all = 0;
	for (int i = 0; i < 17; i++) {
		if (graph[i].size() == 0)
			continue;

		for (int j = 0; j < graph[i].size(); j++) {
			mx = max(mx, ++cnt[graph[i][j] << i]);
			all++;
		}
	}
	cout << all - mx << endl;
	return 0;
}
