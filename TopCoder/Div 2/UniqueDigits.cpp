//TC 280-D2-1

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class UniqueDigits {

public:
	bool isUnique(string str) {
		for (unsigned int i = 0; i < str.length(); i++) {
			for (unsigned int j = i + 1; j < str.length(); j++) {

				if (str.length() > 1)
					if (str[i] == str[j])
						return 0;

			}
		}

		return 1;
	}

	int count(int n) {
		int sum = 0;
		string str;
		stringstream out;

		for (int i = 1; i < n; i++) {

			//Check uniqueness
			out << i;
			str = out.str();

			if (isUnique(str))
				sum++;

			out.str("");
			str.clear();

		}

		return sum;
	}
};
int main() {

	UniqueDigits a;
	cout << a.count(101);

	return 0;
}
