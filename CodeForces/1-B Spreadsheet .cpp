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
#include <ctype.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
typedef long long ll;
using namespace std;

int powr(int x, int n) {
	if (n == 0)
		return 1;

	int p = powr(x, n / 2);
	int res = p * p;
	if (n % 2 == 1)
		res *= x;

	return res;
}
int main() {

	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		bool dig = 0, ch = 0;
		fo(i,str.size()) {
			if (isdigit(str[i]))
				dig = 1;
			if (isalpha(str[i]) && dig)
				ch = 1;
		}

		if (dig && ch) {
			int r, c;
			sscanf(str.c_str(), "R%dC%d", &r, &c);

			string col = "", tmp = "";
			while (c) {
				if (c % 26 == 0)
					tmp = "Z",c--;
				else
					tmp = (c % 26) + '@';
				col = tmp + col;
				c /= 26;
			}
			cout << col << r << endl;
		}

		else {
			int idx = 0;
			while (!isdigit(str[++idx]))
				;
			string col = str.substr(0, idx);
			int r = atoi(str.substr(idx, str.size() - idx).c_str());
			int c = 0;
			idx = 0;
			for (int i = col.size() - 1; i > -1; i--) {
				c += (col[i] - '@') * powr(26, idx++);
			}

			printf("R%dC%d\n", r, c);

		}
	}
	return 0;
}
