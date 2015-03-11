/*
 * E-Mail : khaled.samy@fci-cu.edu.eg
 * TopCoder Handle : Khaled91
 * Another buggy code by Khaled Samy;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
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
#include <valarray>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)					(int)v.size()
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

ll ans[30001];
int coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
int main() {
	ans[0] = 1;

	for (int i = 0; i < 11; i++) {
		int cur = coins[i];
		for (int j = cur; j <= 30000; j++)
			ans[j] = ans[j] + ans[j - cur];
	}

	int a,b;
	while (1) {
		scanf("%d.%d",&a,&b);
		if (a==0 && b==0)
			return 0;
		int ind =  ( a * 100 + b);
		printf("%6.2f%17lld\n", (float)ind/100,ans[ind]);

	}
	return 0;
}
