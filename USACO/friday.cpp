/*
 ID: fci_isl1
 LANG: C++
 PROG: friday
 */

#include <iostream>

using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int res[7] = { 1 };
int main() {

	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);

	int n;
	cin >> n;
	n += 1900;

	int last = 0;
	for (int i = 1900; i < n; i++) {
		mon[1] = (i % 400 == 0 || (i%100 && i % 4 == 0) ) ? 29 : 28;

		for (int j = 0; j < 12; j++) {

			if ((i + 1 == n) && (j == 11))//last year && last month
				break;

			res[last = (mon[j] + last) % 7]++;
		}
	}
	cout << res[0];
	foo(i,1,7)
		cout << " " << res[i];
	cout << endl;
	return 0;
}
