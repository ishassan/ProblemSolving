#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

typedef unsigned int uint;

using namespace std;

vector<uint> s, b;

uint abs(uint a, uint b) {
	if (a > b)
		return a - b;
	return b - a;
}

uint min(uint a, uint b) {
	if (a < b)
		return a;
	return b;
}

void cmpS(int idx, int val, int n) {
	foo(i,idx+1,n) {
		s.push_back(val * s[i]);
		cmpS(i, val * s[i], n);
	}
}
void cmpB(int idx, int val, int n) {
	foo(i,idx+1,n) {
		b.push_back(val + b[i]);
		cmpS(i, val + b[i], n);
	}
}

int main() {

	uint n;
	cin >> n;

	uint x, xx;
	fo(i,n) {
		cin >> x >> xx;
		s.push_back(x);
		b.push_back(xx);
	}

	fo(i,n)
		cmpS(i, s[i], n);

	fo(i,n)
		cmpB(i, b[i], n);

	int sz1 = s.size();
	int sz2 = b.size();

	uint ret = 1 << 28;
	fo(i,sz1) {
		fo(j,sz2) {
			if (abs(s[i], b[j]) == 0)
				continue;
			ret = min(ret, abs(s[i], b[j]));

		}
	}

	if (ret == 1 << 28)
		cout << min(*min_element(s.begin(), s.end()), *min_element(b.begin(),
				b.end()));

	else
		cout << ret;

	return 0;
}
