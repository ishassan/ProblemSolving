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
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

int memo[1000][1000];
string str;

int editdist(int s, int e) {
	if (s >= e)
		return 0;

	if (memo[s][e] != -1)
		return memo[s][e];

	int c1 = editdist(s + 1, e) + 1;
	int c2 = editdist(s,e-1)+1;
	int c3 = editdist(s + 1, e - 1) + (str[s] != str[e]);

	return memo[s][e] = min(c1,min(c2,c3));
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tst;
	cin >> tst;

	fo(t,tst) {
		memset(memo, -1, sizeof memo);
		cin >> str;
		cout << "Case " << t + 1 << ": " << editdist(0, str.size() - 1) << endl;
	}

	return 0;
}
