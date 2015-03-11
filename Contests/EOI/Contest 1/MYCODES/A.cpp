#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

bool cmp2(string a, string b) {
	if(a==b)
		return 1;

	if (a[1] == 'H')
		return 0;

	if (a[1] == 'S') {
		if (b[1] == 'H')
			return 1;
		return 0;
	}
	if (a[1] == 'D') {
		if (b[1] == 'H' || b[1] == 'S')
			return 1;
		return 0;
	}

	return 1;

}
bool cmp(string a, string b) {


	if (a[0] == b[0])
		return cmp2(a, b);

	if (isdigit(a[0]) && isdigit(b[0]))
		return a[0] < b[0];

	else if (isdigit(a[0]) && isalpha(b[0]))
		return 1;

	else if (isdigit(b[0]) && isalpha(a[0]))
		return 0;

	else if (isalpha(a[0]) && isalpha(b[0])) {

		if (a[0] == 'A')
			return 0;

		if (a[0] == 'K') {
			if (b[0] == 'A')
				return 1;
			return 0;
		}

		if (a[0] == 'Q') {
			if (b[0] == 'A' || b[0] == 'K')
				return 1;
			return 0;
		}

		if (a[0] == 'J') {
			if (b[0] == 'A' || b[0] == 'K' || b[0] == 'Q')
				return 1;
			return 0;
		}

		if (a[0] == 'T')
			return 1;

	}

}

int main() {

	int k;
	cin >> k;

	vector<string> a(k),b(k);

	fo(i,k)
		cin >> a[i];

	fo(i,k)
		cin >> b[i];

	sort(b.begin(), b.end(),cmp);

	int ret = 0;
	for (int i = 0; i < k; i++) {
		vector<string>::iterator it =
				lower_bound(b.begin(), b.end(), a[i], cmp);


		if (it == b.end())
			continue;

		ret++;
		b.erase(it);
	}

	cout << ret << endl;
	return 0;
}

