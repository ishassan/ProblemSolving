/*
 ID: fci_isl1
 LANG: C++
 TASK: milk3
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef vector<int> vi;

bool res[21] = { 0 };
int sz = 0;
bool bucket[21][21][21] = { 0 };
map<char, int> capacity;

struct state {
	map<char, int> m;
	char third;
};

bool pour(char from, char to, map<char, int>& m) {
	if (m[from] == 0)
		return 0;

	int val = min(m[from], capacity[to] - m[to]);
	m[from] -= val;
	m[to] += val;

	if (bucket[m['a']][m['b']][m['c']])
		return 0;
	bucket[m['a']][m['b']][m['c']] = 1;
	return 1;
}

void BFS() {
	map<char, int> m, mm;
	char third;

	m['a'] = m['b'] = 0, m['c'] = capacity['c'];

	state st;
	st.m = m, st.third = 'c';

	queue<state> q;
	q.push(st);

	while (!q.empty()) {
		int size = q.size();
		while (size--) {

			m = q.front().m;
			third = q.front().third;

			q.pop();

			if (m['a'] == 0)
				if (!res[m['c']])
					res[m['c']] = 1, sz++;

			for (char c = 'a'; c < 'd'; c++) {
				if (c == third)
					continue;

				mm = m;
				if (pour(c, third, mm)) {
					st.m = mm;

					for (char cc = 'a'; cc < 'd'; cc++)
						if (cc != c && cc != third)
						{st.third = cc; break;}

					q.push(st);
				}

				mm = m;
				if (pour(third, c, mm)) {
					st.m = mm;

					for (char cc = 'a'; cc < 'd'; cc++)
						if (cc != c && cc != third)
						{st.third = cc;break;}

					q.push(st);
				}

			}
		}
	}
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	map<char, int> m;
	cin >> m['a'] >> m['b'] >> m['c'];

	capacity = m;

	BFS();

	for (int i = 0; i < 21; i++)
		if (res[i]) {
			cout << i, sz--;

			if (sz == 0) {
				cout << endl;
				return 0;
			}

			cout << " ";
		}

	return 0;
}
