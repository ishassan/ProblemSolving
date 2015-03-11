//UVa 160
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {

	int n;
	while (1) {

		cin >> n;
		if (n == 0)
			break;

		int countPrimes[1000] = { 0 };

		for (int i = 2; i <= n; i++) {

			int t = i;

			for (int j = 2; j <= t; j++) {

				while (t % j == 0) {
					countPrimes[j]++;
					t /= j;
				}
			}
		}

		//display result
		cout << setw(3) << n << "! =";

		int count = 0;
		for (int i = 2; i <= n; i++) {

			if (countPrimes[i]) {

				if (count == 15) {
					cout << endl << "      "; //6 spaces
					count = 0;
				}

				cout << setw(3) << countPrimes[i];

				count++;

			if(i+1>n) //the last test case
				break;
		}
	}
	cout<<endl;
}

return 0;
}
