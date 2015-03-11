#include<iostream>
#include<string>
using namespace std;
string a;
int n;
long long memo[6000];
long long decode(int i) {
	if (i == n)
		return 1;
	if (i > n)
		return 0;

	if (memo[i] != -1)
		return memo[i];
	if (a[i] == '0')
		return 0;
	long long r = decode(i + 1);
	if (a[i] == '1')
		r += decode(i + 2);
	if (a[i] == '2' && a[i + 1] < '7')
		r += decode(i + 2);
	return memo[i] = r;
}
int main() {
	while (cin >> a) {
		if (a == "0")
			return 0;
		memset(memo, -1, sizeof memo);
		n = a.size();
		cout << decode(0) << endl;
	}
	return 0;
}
