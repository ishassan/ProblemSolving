#include<iostream>
#include<map>
using namespace std;
map<long long , long long > m;
unsigned long long coins(unsigned long long n) {
	if (n / 2 + n / 3 + n / 4 <= n)
		return n;
	if (m.find(n) != m.end())
		return m[n];
	long long r1 = n;
	long long r2 = coins(n / 2) + coins(n / 3) + coins(n / 4);
	return m[n] = max(r1, r2);
}
int main() {
	unsigned long long n;
	while (cin >> n) {
		m.clear();
		cout << coins(n) << endl;
	}
	return 0;
}
