//TC 230-D2-1

#include <iostream>
#include <vector>

using namespace std;

class InequalityChecker {

public:

	int pow(int base, int power) {
		int res = 1;
		for (int i = 0; i < power; i++) {
			res *= base;
		}

		return res;
	}

	int gcd(int num1, int num2) {
		int smallest = (num1 < num2) ? num1 : num2;

		for (int i = smallest; i > 0; i--) {
			if (num1 % i == 0 && num2 % i == 0)
				return i;
		}

		return 1;
	}

	vector<int> getDifferences(int n) {
		vector<int> res;
		int s = 0, S = 0;
		int numerator;
		int gcdValue;
		for (int i = 1; i < n; i++) {
			s += pow(i, 3);
		}

		for (int i = 1; i <= n; i++) {
			S += pow(i, 3);
		}

		//simplifying the fraction
		numerator = (4*(s+S)) - (2*pow(n,4));
		gcdValue = gcd(numerator,8);


		res.push_back(numerator/gcdValue);
		res.push_back(8/gcdValue);

		return res;


	}
};

int main() {

	vector<int> a;
	InequalityChecker x;

	a = x.getDifferences(100);

	cout<<a[0]<<endl<<a[1];

	return 0;
}
