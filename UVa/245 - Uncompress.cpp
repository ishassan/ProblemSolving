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

using namespace std;

vector<string> list;
void display(vs& s) {
	fo(i,s.size()) {
		cout << s[i];
			cout << endl;
	}
}
int main() {


	string cur;
	vs lines;

	while (getline(cin, cur)) {
		if (cur == "0")
			break;

		lines.push_back(cur);
	}

	fo(i,lines.size()) {

		string str;
		fo(j,lines[i].size()) {
			if (isdigit(lines[i][j])) {
				str.clear();
				for (j; j < lines[i].size(); j++) {
					if (isdigit(lines[i][j]))
						str += lines[i][j];

					else
						break;
				}

				int pos = list.size() - (atoi(str.c_str()));

				lines[i].replace(j - str.size(), str.size(), list[pos]);
				j += list[pos].size() - str.size();
				list.push_back(list[pos]);
				list.erase(list.begin() + pos);

				str.clear();
			}

			if (!isalnum(lines[i][j])) {

				while (j + 1 < lines[i].size() && !isalnum(lines[i][j + 1]))
					j++;

				if (str.size() > 0)
					list.push_back(str), str.clear();

			} else
				str += lines[i][j];

		}
		if (str.size() > 0)
			list.push_back(str);

	}

	display(lines);
	return 0;
}
