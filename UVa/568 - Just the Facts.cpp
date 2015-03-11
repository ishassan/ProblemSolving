//UVa 568
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

int count_zeros(int n) {

	int c2 = 0, c5 = 0;

	for (int i = 2; i <= n; i++) {

		int t = i;
		while (t % 2 == 0)
			t /= 2, c2++;
		while (t % 5 == 0)
			t /= 5, c5++;
	}

	return min(c2, c5);
}

int last_digit(int n) {

	int c2, c5;
	c2 = c5 = count_zeros(n);
	int digit = 1;

	for (int i = 2; i <= n; i++) {

		int t = i;
		while (c2 && t % 2 == 0)
			t /= 2, c2--;
		while (c5 && t % 5 == 0)
			t /= 5, c5--;

		digit = (digit * t) % 10;

	}

	return digit;
}
int main() {

	int n;
	while(cin>>n){
		cout<<setw(5)<<n<<" -> "<<last_digit(n)<<endl;
	}

	return 0;
}
