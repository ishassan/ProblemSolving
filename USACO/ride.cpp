/*
  ID: fci_isl1
  LANG: C++
  PROG: ride
 */

#include <iostream>
#include <string>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

int main() {

	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);


	string a, b;
	cin >> a >> b;

	int score1 = 1, score2 = 1, mod1, mod2, sz1 = a.size(), sz2 = b.size();
	fo(i,sz1) {
		score1 *= a[i] - 'A' + 1;
		if (i < sz2)
			score2 *= b[i] - 'A' + 1;
	}
	mod1 = score1 % 47, mod2 = score2 % 47;

	(mod1 == mod2) ? cout << "GO\n" : cout << "STAY\n";

	return 0;
}
