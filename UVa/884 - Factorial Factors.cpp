//UVa 884
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1000001;
const int S = 100001;
int counts[N];
bool primes[S];

void sieve() {

	memset(primes, 1, S);
	primes[0] = primes[1] = 0;

	for (int i = 4; i < S; i += 2)
		primes[i] = 0;

	for (int i = 3; i * i <= S; i += 2) {
		if (primes[i]) {
			for (int j = i * 2; j < S; j += i)
				primes[j] = 0;
		}
	}
}

int main() {

	sieve();

	counts[0] = counts[1] = 0;

	for (int i = 2; i < N; i++) {

		counts[i] = counts[i - 1];

		int t = i;

		while(t%2==0){
			counts[i]++;
			t /=2;
		}

		for (int j = 3; j*j<=N && j <= t; j+=2) {

			if (primes[j])
				while (t % j == 0) {
					counts[i]++;
					t /= j;
				}
		}

		if(t>1)
			counts[i]++;
	}

	int n;

	while (cin >> n) {

		cout << counts[n] << endl;

	}

	return 0;
}

