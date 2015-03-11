/*
 ID: fci_isl1
 LANG: C++
 TASK: pprime
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool isprime(long long n) {
	if (n == 2)
		return true;

	if (n < 2 || n % 2 == 0)
		return false;

	for (long long i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

vector<int> pal;

int main() {
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);

	int n, m;
	cin >> m >> n;

	int mm = m, digm = 0;
	while (mm > 0)
		mm /= 10, digm++;

	int nn = n, dign = 0;
	while (nn > 0)
		nn /= 10, dign++;

	pal.push_back(2), pal.push_back(3), pal.push_back(5), pal.push_back(7);
	pal.push_back(11);

	if (digm <= 3 && dign >= 3)
		for (int i = 1; i < 10; i += 2)
			for (int j = 0; j < 10; j++)
				pal.push_back(100 * i + 10 * j + i);

	if (digm <= 4 && dign >= 4)
		for (int i = 1; i < 10; i += 2)
			for (int j = 0; j < 10; j++)
				pal.push_back(1000 * i + 100 * j + 10 * j + i);

	if (digm <= 5 && dign >= 5)
		for (int i = 1; i < 10; i += 2)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					pal.push_back(10000 * i + 1000 * j + 100 * k + 10 * j + i);

	if (digm <= 6 && dign >= 6)
		for (int i = 1; i < 10; i += 2)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					pal.push_back(100000 * i + 10000 * j + 1000 * k + 100 * k
							+ 10 * j + i);

	if (digm <= 7 && dign >= 7)
		for (int i = 1; i < 10; i += 2)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					for (int l = 0; l < 10; l++)
						pal.push_back(1000000 * i + 100000 * j + 10000 * k
								+ 1000 * l + 100 * k + 10 * j + i);

	int start = 0, end = 0;
	while (pal[start] < m)
		start++;

	if (dign >= 8)
		end = pal.size();

	else
		while (pal[end] <= n)
			end++;

	for (int i = start; i < end; i++)
		if (isprime(pal[i]))
			cout << pal[i] << endl;
	return 0;
}

/*
	if(dign<8)
	return 0;

	pal.clear();
	end =0;

	if (digm <= 8 && dign >= 8)
		for (int i = 1; i < 10; i += 2)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					for (int l = 0; l < 10; l++)
						pal.push_back(10000000 * i + 1000000 * j + 100000 * k
								+ 10000 * l + 1000 * l + 100 * k + 10 * j + i);


	//pal.push_back(100000001);

	while (pal[end] <= n)
		end++;

	for (int i = 0; i < end; i++)
		cout << pal[i] << endl;
*/
