#include<iostream>
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main() {
	bool second = 0;
	int tst;
	while (cin >> tst) {
		if (second) {
			cout << endl;
		}
		second = 1;
		map<string, int> family;
		vector<string> famName;
		for (int i = 0; i < tst; i++) {
			string names;
			cin >> names;
			family[names] = 0;
			famName.push_back(names);

		}
		for (int i = 0; i < tst; i++) {
			string one;
			cin >> one;
			int m;
			int n;
			cin >> m >> n;
			if (n == 0)
				continue;
			family[one] += m % n;
			family[one] -= m;
			for (int i = 0; i < n; i++) {
				string two;
				cin >> two;
				family[two] += m / n;
			}
		}
		for (int i = 0; i < famName.size(); i++) {
			cout << famName[i] << " " << family[famName[i]] << endl;
		}

	}
	return 0;
}
