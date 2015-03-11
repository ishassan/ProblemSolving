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
#include <cmath>
#include <queue>
#include <set>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int b;
char tochar(int n) {
	if (n < 10)
		return n + '0';
	else
		return n - 10 + 'A';
}
string toB(int dec) {
	string res;
	while (dec) {
		res += tochar(dec % b);
		dec /= b;
	}
	reverse(res.begin(), res.end());
	return res;
}

bool palindrome(string& str) {
	int sz = str.size();
	int lim = sz / 2;
	fo(i,lim) {
		if (str[i] != str[sz - 1 - i])
			return 0;
	}
	return 1;
}
int main() {
	cin >> b;

	foe(i,1,300) {
		string str = toB(i * i);
		if (palindrome(str))
			cout << toB(i) << " " << str << endl;
	}
	return 0;
}
