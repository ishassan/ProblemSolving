#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <numeric>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

int main() {

	int n;
	while (cin >> n) {
		if (n == 0)
			return 0;
		cout << n << " => ";
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		long long c = 2, res = 1;
		foe(i,2,n) {
			res += c;
			c += 2;
		}

		cout << res << endl;
	}

	return 0;
}
