#include <iostream>
#include <string>
using namespace std;

int main() {

	long int n;
   
	string cur;

	cin >> n;
	cin.ignore(100, '\n');

	string* str = new string[n];
    
	for (int i = 0; i < n; i++) {

		getline(cin, str[i]);
	}

	for (int i = 0; i < n; i++) {

		cur = str[i];
		for (int j = 0; j < cur.length(); j++) {
			if (cur[j] == ')' && j > 0) {
				if (cur[j - 1] == '(') {
					cur.erase(j - 1, 2);
					j = -1;
				}
			}

			else if (cur[j] == ']' && j > 0) {
				if (cur[j - 1] == '[') {
					cur.erase(j - 1, 2);
					j = -1;
				}

			}

		}

		if (cur.length() == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}


	exit(0);
}

