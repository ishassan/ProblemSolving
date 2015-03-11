#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

string chess[110];
int n;
int countB(int i, int j) {
	int ret = 0;
	for (int r = 1; i + r < n && j + r < n; r++) {
		if (chess[i + r][j + r] == 'B') {
			ret++;
			break;
		}
	}

	for (int l = 1; i + l < n && j - l >-1; l++) {
		if (chess[i + l][j - l] == 'B') {
			ret++;
			break;
		}
	}

	return ret;
}
int main() {

	cin >> n;
	fo(i,n)
		cin >> chess[i];

	int ret = 0;
	fo(i,n)
		fo(j,n) {

			if (chess[i][j] == 'B')
				ret += countB(i, j);

		}

	cout << ret << endl;

	return 0;
}
