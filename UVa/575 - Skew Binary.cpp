// UVa 575
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;

int main() {

	double power=0;
	long int res = 0;
	string num;

	while (1) {

		getline(cin, num);

		if (num[0] - '0' == 0)
			break;

		for (int j = 0; j < num.length(); j++) {
			power = num.length() - j;

			res += round((num[j] - '0') * (pow(2, power) - 1));
		}

		cout << res<<endl;
		res = 0;
	}

	return 0;
}
