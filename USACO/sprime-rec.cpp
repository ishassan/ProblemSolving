/*
 ID: fci_isl1
 LANG: C++
 TASK: sprime
 */

#include <iostream>

using namespace std;

bool isprime(int n) {
	if (n == 2)
		return true;
	if (n < 2 || n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int digits[] = { 1, 3, 7, 9 };

void rec(int ndig, int num) {
	if (ndig == 1)
		cout << num << endl;

	for (int i = 0; i < 4; i++) {
		int test = num * 10 + digits[i];
		if (isprime(test))
			rec(ndig - 1, test);
	}

}

int main() {
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);

	int primes[] = { 2, 3, 5, 7 };

	int n;
	cin >> n;

	for (int i = 0; i < 4; i++)
		rec(n, primes[i]);

	return 0;
}
