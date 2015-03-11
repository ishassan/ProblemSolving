//UVa 10200
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {

	if (n < 2 || n % 2 == 0)
		return 0;

	if (n == 2)
		return 1;

	int sq = (int) sqrt(n) + 1;

	for (int i = 3; i < sq; i += 2)
		if (n % i == 0)
			return 0;

	return 1;
}
int main() {

	int a, b;
	cout.setf(ios_base::fixed);
	cout.precision(2);

	int primes[10002];
	primes[0] = 1;

	for (int i = 1; i < 10002; i++) {
		primes[i] = primes[i - 1] + isPrime(i * i + i + 41); //accumulate
	}

	while (cin >> a >> b) {

		int total = b - a + 1;

		double range = (a>0)? primes[b] - primes[a-1] : primes[b] - primes[a] + 1;	//end - begin to get the interval between a,b

		cout << range * 100 / total + 1e-9 << endl;

		//we add 1e-9 to round, we can use this way instead
		/*
				 double x = range * 100 / total;
				 x = round(x*100) / 100;
				 cout<<x;

				 */

	}
	return 0;
}

