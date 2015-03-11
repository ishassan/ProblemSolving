#include <iostream>
#include <map>
using namespace std;

int powr(int n, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return n;

	int x = powr(n, p / 2);
	x = x * x;

	if (p % 2 != 0)
		x *= n;

	return x;
}
int main() {
	freopen("teams.in", "rt", stdin);

	int n, tst = 1;
	while (cin >> n) {
		if (n == 0)
			return 0;

		cout << tst++ << ". ";

		cout << powr(2, n - 1) - 1 << endl;
	}

	return 0;
}
