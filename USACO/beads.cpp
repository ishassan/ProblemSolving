/*
	 ID: fci_isl1
	 LANG: C++
	 PROB: beads
*/

#include <iostream>
#include <string>

using namespace std;

int n;
string str;
bool memo[30];

int right(int ind, char color) {

	if (ind == n)
		ind = 0;

	int ret = 0;
	while (str[ind] == color || str[ind] == 'w' ) {
		memo[ind]=1;

		ret++;
		if (++ind == n)
			ind = 0;
	}

	return ret;
}

int left(int ind, char color) {
	ind--;	//for not counting the same bead twice
	if (ind < 0)
		ind = n - 1;

	int ret = 0;
	while (str[ind] == color || str[ind] == 'w') {
		if(memo[ind])
			break;

		ret++;
		if (--ind < 0)
			ind = n - 1;
	}

	return ret;
}

void memset(){
	for(int i=0; i<30; i++)
		memo[i]=0;
}

int main() {

	freopen("beads.in", "r", stdin);
	freopen("beads.out","w",stdout);


	cin >> n >> str;

	bool r = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'r')
			r = 1;

		else if (str[i] == 'b')
			b = 1;

		if (r && b)
			break;
	}

	if (!r || !b) {
		cout << n << endl;
		return 0;
	}

	int mx = 0, val;
	for (int i = 0; i < n; i++) {
		memset();
		if (mx < (val = right(i, 'r') + left(i, 'b')))
			mx = val;

		memset();
		if (mx < (val = right(i, 'b') + left(i, 'r')))
			mx = val;
	}
	cout << mx << endl;

	return 0;
}
