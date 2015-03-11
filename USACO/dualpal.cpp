/*
 ID: fci_isl1
 LANG: C++
 PROB: dualpal
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

string convert(int num, int toBase) {

	string res = "";
	while (num > 0) {
		res += (num % toBase);
		num /= toBase;
	}
	reverse(res.begin(), res.end());

	return res;
}

int main() {
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	int n, s;
	cin >> n >> s;

	int nxt = s + 1;
	string str;
	while (n) {
		int num = 0;
		for (int i = 2; i < 11 && num < 2; i++) {
			str = convert(nxt,i);
			if(isPalindrome(str))
				num++;
		}

		if(num==2){
			cout<<nxt<<endl;
			n--;
		}
		nxt++;
	}

	return 0;
}
