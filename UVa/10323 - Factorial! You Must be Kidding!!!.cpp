#include <iostream>
using namespace std;
int fact(int num) {
	if (num == 1)
		return 1;
	return fact(num - 1) * num;
}
int main() {
	int n;

	while (cin >> n) {
		if (n < 0) {
			if (n % 2 == 0)
				cout << "Underflow!" << endl;
			else
				cout << "Overflow!" << endl;
		} else if (n < 8 && n >= 0)
			cout << "Underflow!" << endl;
		else if (n > 13)
			cout << "Overflow!" << endl;

		else if (n == 13)
			cout << "6227020800" << endl;
		else
			cout << fact(n) << endl;
	}

	return 0;
}
