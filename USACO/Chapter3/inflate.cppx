/*
ID: tito_911
PROG: inflate
LANG: C++
*/
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

int points[10001], problems[10001];
int Time, sz;

//int memo[10001][10001];
int dp[10001][2];

/*int get(int remTime, int idx) {
	if (remTime < 0)
		return -OO;
	if (idx >= sz)
		return 0;
	int &m = memo[remTime][idx];
	if (m != -1)
		return m;
	m = max(get(remTime, idx + 1), get(remTime - problems[idx], idx)
			+ points[idx]);
	return m;
}*/
int get2() {
	for (int idx = sz - 1; idx >= 0; idx--) {
		for (int remTime = 0; remTime <= Time; remTime++) {
			int &m = dp[remTime][idx % 2];
			m = dp[remTime][(idx + 1) % 2];
			if (remTime - problems[idx] >= 0)
				m = max(m, dp[remTime - problems[idx]][idx % 2] + points[idx]);
		}
	}
}
int main() {

	freopen("inflate.in", "rt", stdin);
	freopen("inflate.out", "wt", stdout);
	scanf("%d%d", &Time, &sz);
	loop(i,sz)
		scanf("%d%d", &points[i], &problems[i]);
	//CLR(memo,-1);

	get2();
	printf("%d\n", dp[Time][0]);
	return 0;
}
