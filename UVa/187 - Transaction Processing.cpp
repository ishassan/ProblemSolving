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
string index(int x, vector<pair<int, string> > data) {
	for (int i = 0; i < data.size(); i++)
		if (x == data[i].first)
			return data[i].second;
	return "";
}
int main() {

	string in;
	vector<pair<int, string> > indata;

	while (getline(cin, in)) {
		string num = in.substr(0, 3);
		if (num == "000")
			break;

		string inn = in.substr(3, in.size() - 3);
		indata.push_back(make_pair(atoi(num.c_str()), inn));
	}
	string one;
	string input;

	vector<pair<int, vector<int> > > sec;
	vector<int> n;
	while (getline(cin, input)) {
		string nuM;
		bool b = false;
		vector<int> acc;
		one = input.substr(0, 3);
		if (one == "000")
			break;
		one += input.substr(3, 3);
		input = input.erase(0, 6);
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ' ')
				continue;
			nuM += input[i];
		}
		int num = atoi(nuM.c_str());
		n.push_back(num);
		string tmp1;
		string tmp2;
		tmp1 = one.substr(0, 3);
		tmp2 = one.substr(3, 3);

		acc.push_back(atoi(tmp2.c_str()));
		for (int i = 0; i < sec.size(); i++) {
			if (atoi(tmp1.c_str()) == sec[i].first) {
				sec[i].second.push_back(atoi(tmp2.c_str()));
				b = 1;
				break;
			}
		}
		if (b == 1)
			continue;
		sec.push_back(make_pair(atoi(tmp1.c_str()), acc));
	}
	vector<double> mod;
	for (int i = 0; i < sec.size(); i++) {
		int sum = 0;
		double res = 0;
		mod.clear();
		for (int j = 0; j < sec[i].second.size(); j++) {
			sum += n[j];
			res += n[j] / 100.00;
			mod.push_back(n[j] / 100.00);
		}
		for (int j = 0; j < sec[i].second.size(); j++)
			n.erase(n.begin());
		if (sum == 0)
			continue;
		cout << "*** Transaction " << sec[i].first << " is out of balance ***";
		cout << endl;
		for (int j = 0; j < sec[i].second.size(); j++) {

			string tmp = index(sec[i].second[j], indata);
			cout << sec[i].second[j] << " " << tmp << setw(41 - tmp.size());
			cout << fixed << setprecision(2) << mod[j] << endl;
		}
		cout << 999 << " Out of Balance";
		if (res < 0)
			cout << setw(41 - 14) << fabs(res);
		else
			cout << setw(41 - 14) << "-" << res;

		cout << endl << endl;

	}

	return 0;
}
