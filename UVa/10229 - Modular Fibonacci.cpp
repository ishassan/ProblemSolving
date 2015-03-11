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
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define pb(n)       push_back(n)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef unsigned long long ull;
typedef vector<ull> vull;
typedef vector<vull> vull2;

vull2 unit(2, vull(2));
vull2 one(2, vull(2));

int n, m;

ull powr(ull n, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return n;

	ull x = powr(n, p / 2);
	x = x * x;

	if (p % 2 != 0)
		x *= n;

	return x;
}

vull2 mpow(vull2 u, int p) {
	if (p == 0)
		return one;
	if (p == 1)
		return u;

	vull2 x = mpow(u, p / 2);
	vull2 res(2, vull(2));
	res[0][0] = (x[0][0] * x[0][0]) + (x[0][1] * x[1][0]);
	res[0][1] = (x[0][0] * x[0][1]) + (x[0][1] * x[1][1]);
	res[1][0] = (x[1][0] * x[0][0]) + (x[1][1] * x[1][0]);
	res[1][1] = (x[1][0] * x[0][1]) + (x[1][1] * x[1][1]);

	if (p % 2 != 0) {
		x = res;
		res[0][0] = x[0][0] * u[0][0] + x[0][1] * u[1][0];
		res[0][1] = x[0][0] * u[0][1] + x[0][1] * u[1][1];
		res[1][0] = x[1][0] * u[0][0] + x[1][1] * u[1][0];
		res[1][1] = x[1][0] * u[0][1] + x[1][1] * u[1][1];
	}

	fo(i,res.size()) {
		fo(j,res[i].size()) {
			res[i][j] %= powr(2, m);
		}
	}
	return res;
}

int fib(ull n) {
	if (n < 2)
		return n;

	vull2 res = mpow(unit, n);
	return res[0][1];
}
int main() {

	unit[0][0] = 0;
	unit[0][1] = unit[1][0] = unit[1][1] = 1;
	one[0][0] = one[0][1] = one[1][0] = one[1][1] = 1;


	while (cin >> n >> m) {
		cout << fib(n) << endl;
	}

	return 0;
}
