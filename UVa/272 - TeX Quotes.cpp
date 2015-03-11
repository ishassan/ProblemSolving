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
	vector<string> list;
	string in;
	string out = "";
	bool open = 0;
	while (getline(cin, in,'\0')) {
		list.push_back(in);
	}
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < list[i].size(); j++) {
			if (list[i][j] == '\"') {
				if (open)
					open = 0, out += "\'\'";
				else
					open = 1, out += "``";
			}

			else
				out += list[i][j];
		}
		cout << out;
		if (i + 1 < list.size())
			cout << endl;
		out.clear();
	}
	return 0;
}
