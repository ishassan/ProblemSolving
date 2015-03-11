/*
 ID: fci_isl1
 LANG: C++
 TASK: crypt1
 */
#include <iostream>
#include <set>
using namespace std;

int main() {

	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	int n, m;
	set<int> s;
	int v[10];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> m, s.insert(m), v[i] = m;

	int count = 0, num, dig, rem;
	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++)
			for (int c = 0; c < n; c++)
				for (int d = 0; d < n; d++)
					for (int e = 0; e < n; e++) {

						num = v[d] * v[a];
						dig = num % 10, num /= 10, rem = num % 10;
						if (s.find(dig) == s.end())
							continue;

						num = v[d] * v[b] + rem;
						dig = num % 10, num /= 10, rem = num % 10;
						if (s.find(dig) == s.end())
							continue;

						num = v[d] * v[c] + rem;
						dig = num % 10, num /= 10, rem = num % 10;
						if (s.find(dig) == s.end() || rem > 0)
							continue;

						num = v[e] * v[a];
						dig = num % 10, num /= 10, rem = num % 10;
						if (s.find(dig) == s.end())
							continue;

						num = v[e] * v[b] + rem;
						dig = num % 10, num /= 10, rem = num % 10;
						if (s.find(dig) == s.end())
							continue;

						num = v[e] * v[c] + rem;
						dig = num % 10, num /= 10, rem = num % 10;
						if (s.find(dig) == s.end() || rem > 0)
							continue;

						int mult = (v[a] + (10 * v[b]) + (100 * v[c])) * (v[d]
								+ 10 * v[e]);

						bool f = 1;
						while (mult > 0) {
							if (s.find(mult % 10) == s.end()) {
								f = 0;
								break;
							}
							mult /= 10;
						}
						if (f)
							count++;

					}
	cout << count << endl;
	return 0;
}
