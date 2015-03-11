//UVa 621
#include <iostream>
#include <string>

using namespace std;

int main() {

	string in;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin>>in;

		if (in == "1" || in == "4" || in == "78") {
			cout << "+\n";
		}

		else if (in.substr(in.length() - 2, 2) == "35") {
			cout << "-\n";
		}

		else if (in[0] == '9' && in[in.length() - 1] == '4') {
			cout << "*\n";
		}

		else if (in.substr(0, 3) == "190") {
			cout << "?\n";
		}
	}

return 0;
}
