/*
 ID: fci_isl1
 LANG: C++
 TASK: fracdec
 */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int modn[1000000];
int msz=0;
int main() {
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);

	int n, d, ind;
	cin >> n >> d;

	stringstream ss;

	int div = n / d;
	int mod = n % d;

	ss << div;
	ss << ".";
	if (mod == 0) {
		ss<<"0";
		cout << ss.str() << endl;
		return 0;
	}

	int intsz = ss.str().size();
	memset(modn,-1,sizeof modn);

	while (modn[mod]==-1) {
		modn[mod] = msz++;
		n = mod * 10;
		div = n / d;
		mod = n % d;
		ss << div;
	}

	string res = ss.str();

	if (mod == 0 && res[res.size() - 2] != '.')
		res.erase(res.size() - 1, 1);

	if (mod > 0) {
		res = res.insert(modn[mod] + intsz, "(");
		res += ")";
	}

	int sz = res.size();
	for (int i = 0; i < sz; i+= 76) {
		string y(res,i,76);
		cout<<y<<endl;
	}

	return 0;
}
