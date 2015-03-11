#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

string ln;
ll memo[70][70];

ll dp(int s, int e) {
	if (memo[s][e] != -1)
		return memo[s][e];

	ll ret = 0;
	//check substrings inside strings
	//for aoba -> aoa , aba
	for (int i = s + 1; i < e; i++)
		for (int j = i ; j < e; j++)
			if (ln[i] == ln[j])
				ret += 1 + dp(i, j);

	return memo[s][e] = ret;
}

int main() {
	int tst;
	cin >> tst;
	while (tst--) {
		cin >> ln;

		memset(memo, -1, sizeof memo);
		int n = ln.size();
		ll ret = 0;
		//check outer boundries
		//for aba -> a,b,c,aa
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				if (ln[i] == ln[j])
					ret += 1 + dp(i, j);

		cout << ret << endl;
	}
}
