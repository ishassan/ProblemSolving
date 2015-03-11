/*
 ID: fci_isl1
 LANG: C++
 PROB: palsquare
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string str) {
	int sz = str.size();
	if (sz == 0)
		return 0;

	if (sz == 1)
		return 1;

	for (int i = 0; i < sz / 2; i++)
		if (str[i] != str[sz - i - 1])
			return 0;

	return 1;
}

inline char toChar(int i) {
	if (i < 10)
		return i + '0';
	return i - 10 + 'A';
}
string convert(int num, int toBase) {

	string res = "";
	while (num > 0) {
		res += toChar(num % toBase);
		num /= toBase;
	}
	reverse(res.begin(), res.end());

	return res;
}

int main() {
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	int b;
	cin >> b;

	string num;
	for (int i = 1; i < 301; i++) {
		num = convert(i * i, b);
		if (isPalindrome(num))
			cout << convert(i, b) << " " << num << endl;
	}

	return 0;
}
