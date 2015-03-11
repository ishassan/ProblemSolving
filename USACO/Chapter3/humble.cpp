/*
ID: tito_911
PROG: humble
LANG: C++
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

const int OO = (int) 2e9;
const double PI = 2 * acos(0);
const double EPS = 1e-9;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int n, sz;
int nums[101];
int last[101];
int res[100007];

int main() {
	freopen("humble.in", "rt", stdin);
	freopen("humble.out", "wt", stdout);

	scanf("%d%d", & sz, &n);
	loop(i,sz)
		scanf("%d", nums + i);

	res[0] = 1;

	for (int i = 1; i <= n; i++) {
		int mn = OO;
		for (int j = 0; j < sz; j++) {
			while (res[last[j]] * nums[j] <= res[i - 1]) {
				last[j]++;
			}
			mn = min(mn, res[last[j]] * nums[j]);
		}
		res[i] = mn;
	}
	printf("%d\n",res[n]);
	return 0;
}
