/*
 ID: fci_isl1
 LANG: C++
 TASK: ariprog
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool found[125001] = { 0 };
int sqrs[100000];
int ind_sqrs = 0;

int main() {
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	int len, bound, sz, maxDiff;
	bool valid, none = 1;

	cin >> len >> bound;

	sz = bound + 1;

	//storing all possible solutions in array sqrs
	for (int i = 0; i < sz; i++)
		for (int j = i; j < sz; j++)
			found[i * i + j * j] = 1;

	sz = 2 * bound * bound + 1; //m^2 + m^2
	for (int i = 0; i < sz; i++)
		if (found[i])
			sqrs[ind_sqrs++] = i;

	sz = ind_sqrs;

	maxDiff = sqrs[0] + sqrs[sz - 1] / (len - 1);
	//the maximum difference is calculated through this relation

	for (int d = 1; d <= maxDiff; d++) //loop on differences
		for (int i = 0; i < sz; i++) { //loop on numbers

			int sum = sqrs[i];
			valid = 1;
			int j = len - 1;

			while (j--) { //accumulative loop
				sum += d;
				if (sum > 125000 || !found[sum]) {
					valid = 0;
					break;
				}
			}

			if (valid) {
				cout << sqrs[i] << " " << d << endl;
				none = 0;
			}
			valid = 1;
		}

	if (none)
		cout << "NONE\n";

	return 0;
}
