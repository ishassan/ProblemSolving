/*
 ID: fci_isl1
 LANG: C++
 TASK: concom
 */

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
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef stringstream sstr;

bool up[101][101] = { { 0 } };
int down[101][101] = { { 0 } };
int per[101][101];
bool vis[101][101][101] = { { { 0 } } };

int main() {
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);

	int n;
	cin >> n;
	int a, b, c, mx = -1;
	fo(i,n) {
		cin >> a >> b >> c;
		if (a == b)
			continue;
		if (c > 50)
			up[a][b] = 1;
		else
			down[a][b] = c, per[a][b] = c;
		mx = max(mx, max(a, b));
	}

	mx++;
	int x = n/2;
	while (x--) {
		foo(i,1,mx)
			foo(j,1,mx)
				if (up[i][j])
					foo(b,1,mx) {
						if (up[j][b])
							up[i][b] = 1;

						else if (down[j][b] && !up[i][b] && i != b)
							if (!vis[i][j][b]) {
								per[i][b] += down[j][b];
								vis[i][j][b] = 1;
								if (per[i][b] > 50)
									up[i][b] = 1;
							}

					}
	}
	foo(i,1,mx)
		foo(j,1,mx)
			if (up[i][j] && i!=j)
				cout << i << " " << j << endl;

	return 0;
}
