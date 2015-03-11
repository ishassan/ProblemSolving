/*
 *	E-Mail : khaled.samy@fci-cu.edu.eg
 *	TopCoder Handle : Khaled91
 *	Another buggy code by Khaled Samy ;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n) 		        for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 1e9;
const double PI = 2 * acos(0);
const double EPS = 1e-9;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

ll memo[31][1<<3][1<<3];
int n;

ll DP(int i, int bit1, int bit2) {

	if (i == n)
		return 1;

	ll &m = memo[i][bit1][bit2];
	if (m != -1)
		return m;

	m = 0;
	if (__builtin_popcount(bit1) == 3) {
		m = DP(i + 1, bit2, 0);
		return m;
	}

	bool b = 0;

	for (int j = 0; j < 3; ++j) {
		if (i < n - 1)
			if (!(bit1 & (1 << j)) && !(bit2 & (1 << j))) {
				m += DP(i, bit1 | (1 << j), bit2 | (1 << j));
				b = 1;
			}

		if (j < 2)
			if (!(bit1 & (1 << j)) && !(bit1 & (1 << (j + 1)))) {
				m += DP(i, bit1 | (1 << j) | (1 << (j + 1)), bit2);
				if (b)
					break;
			}
	}
	return m;
}
int main() {
	//freopen("zin.txt", "rt", stdin);
	//freopen("zout.txt", "wt", stdout);

	while (scanf("%d", &n) && n != -1) {

		if (n % 2 == 1) {
			cout << "0\n";
			continue;
		}

		CLR(memo,-1);
		cout << DP(0, 0, 0) << endl;
	}
	return 0;
}
