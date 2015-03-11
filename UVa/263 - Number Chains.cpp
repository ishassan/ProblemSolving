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
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
int big(string num) {
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	return atoi(num.c_str());
}
int small(string num) {
	sort(num.begin(), num.end());
	if (num[0] == '0')
		num.erase(num.begin());
	return atoi(num.c_str());
}
int main() {
	string input;
	while (cin >> input) {
		vi biG;
		vi Small;
		vi res;
		vs chain;
		if (input == "0")
			break;
		flag: chain.push_back(input);
		biG.push_back(big(input));
		Small.push_back(small(input));
		int num = big(input) - small(input);
		res.push_back(num);
		stringstream out;
		out << num;
		string check = out.str();
		bool vis = false;
		fo(i,chain.size())
			if (check == chain[i]) {
				vis = true;
				break;
			}
		if (!vis) {
			input = check;
			goto flag;
		}
		cout << "Original number was " << chain[0] << endl;
		fo(i,biG.size())
			cout << biG[i] << " - " << Small[i] << " = " << res[i] << endl;
		cout << "Chain length " << chain.size() << endl << endl;

	}
	return 0;
}
