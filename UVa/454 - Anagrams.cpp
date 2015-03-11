#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
string rev(string str) {
	fo(i,str.size())
		if (str[i] == ' ')
			str.erase(str.begin() + i--);
	return str;
}
bool ang(string str1, string str2) {

	str1 = rev(str1);
	str2 = rev(str2);
	if (str1.size() != str2.size())
		return 0;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	if (str1 == str2)
		return 1;

	return 0;
}

int main() {
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	int tst;
	string input;
	string dumm;
	cin >> tst;
	getline(cin, dumm);
	getline(cin, dumm);
	while (tst--) {
		vs data;

		while (getline(cin, input)) {
			if (input.size() == 0)
				break;
			data.push_back(input);
		}

		sort(data.begin(), data.end());

		fo(i,data.size()) {

			foo(j,i+1,data.size()) {

				if (ang(data[i], data[j])) {

					if (data[i] > data[j])
						cout<<data[j]<<" = "<<data[i]<<endl;

					else
						cout<<data[i]<<" = "<<data[j]<<endl;
				}
			}

		}

		if (tst > 0)
			cout << endl;
	}
	return 0;
}
