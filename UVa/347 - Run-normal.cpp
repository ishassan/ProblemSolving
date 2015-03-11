#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

bool isRun(int num[], int sz) {

	bool vis[8] = { 0 };
	int nVis = 1, start = 0;
	vis[0] = 1;
	while (1) {

		start = (start + num[start]) % sz;

		if (nVis == sz)
			return start == 0;

		if (vis[start])
			return 0;

		vis[start] = 1;
		nVis++;

	}
}

bool isFound(int num[], int size, int e) {
	fo(i,size)
		if (num[i] == e)
			return 1;

	return 0;
}
int main() {
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int n;
	int count = 1;

	while (cin >> n) {
		if (n == 0)
			return 0;
		cout << "Case " << count++ << ": ";
		for (int i = n; i < 9682416; i++) {
			int num[8], ind = 0, dig = i;
			memset(num,-1,sizeof num);

			while (dig > 0) {
				int mod = dig % 10;
				if (isFound(num, ind, mod)) {
					memset(num, -1, sizeof num);
					break;
				}

				num[ind++] = mod;
				dig /= 10;
			}
			if (num[0] == -1) //if repeated
				continue;

			reverse(num, num + ind);
			if (isRun(num, ind)) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
