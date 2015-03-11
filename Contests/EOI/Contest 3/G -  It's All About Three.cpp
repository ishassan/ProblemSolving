#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <numeric>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;


const int MAX = 1000005;
bool primes[MAX] = { 0, 0, 1, 1 };

void seive() {
	for (int i = 4; i < (MAX - 2); i++) {
		primes[i] = 0;
		primes[++i] = 1;
	}

	for (int i = 3; i * i <= MAX; i += 2) {
		if (primes[i])
			for (int j = 2 * i; j < MAX; j += i)
				primes[j] = 0;
	}
}
int main() {

	int n;
	seive();
	while (cin >> n) {
		if (n == -1)
			return 0;

		cout << n << " ";
		if (n < 3) {
			cout << "NO\n";
			continue;
		}

		if (primes[n] && n % 10 == 3) {
			cout << "YES\n";
			continue;
		}


		int nn = n;
		for (int i = 2; i < n; i++) {
			if (primes[i] && n%i==0 && i%10==3) {
				while(nn%i==0)
					nn /=i;
			}
		}

		if (nn > 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
