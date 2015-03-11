#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;
long long dp[500][10];
vector<int> arr;

long long calc(int rem, int cur) {
	//cout<<rem<<" "<<cur<<endl;

	if (cur >= N)
		return (rem<=0);
	long long& x = dp[rem+300][cur];
	if (x != -1)
		return x;
	x = 0;
	for (int i = min(arr[cur], 1); i <= max(arr[cur], -1); i++) {
		x += calc(rem - i, cur + 1);
	}
	return x;
}
pair<int, int> parse(string s) {
	int x, y;
	char ch;
	stringstream ss(s);
	ss >> x;
	if (s.find('d') == -1) {
		return make_pair(0, x);
	}
	ss >> ch;
	ss >> y;
	return make_pair(x, y);
}

int main() {

	freopen("H.in", "r", stdin);
	int n, rem;
	string s;
	cin >> n;
	while (n--) {
		bool flag = true;
		int cnt = 0;
		arr.clear();
		memset(dp, -1, sizeof(dp));
		cin >> rem >> s;
		int prev = 0;
		long long total = 1;

		for (int i = prev; i < (int) s.size(); i++) {
			if (s[i] == '+' || s[i] == '-' || i == s.size() - 1) {
			//	cout << i << endl;
				pair<int, int> val = parse(s.substr(prev, i - prev + (i
						== s.size() - 1)));
				if (!flag)
					val.second *= -1;
				if (val.first == 0)
					cnt += val.second;
				else
					for (int j = 0; j < val.first; j++) {
						total *= val.second;
				//		cout << total << endl;
						arr.push_back(val.second);
					}
				flag = (s[i] != '-');
				prev = i + 1;
			}
		}
	//	for(int i = 0 ; i < arr.size() ; i++) cout<<arr[i]<<endl;
		N = arr.size();
		rem -= cnt;
		long long res = calc(rem, 0);
		total = abs(total);
		if (res == total)
			cout << 1 << endl;
		else if (res == 0)
			cout << 0 << endl;
		else {
			int gcd = __gcd(res, abs(total));
			cout << res / gcd << "/" << total / gcd << endl;
		}
	}
	return 0;
}
