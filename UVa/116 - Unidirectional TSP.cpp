//TC 181 -D2-1		Points =243.07 of 250		Time: 5m
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

#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int mat[10][100];
int vis[10][100] = { 0 };

int r, c;
int counter = 1;
int lis(int i, int j) {

	if (i == r)
		i = 0;

	else if (i < 0)
		i = r - 1;

	if (j == c)
		return 0;

	if (vis[i][j])
		return vis[i][j];

	int c1 = mat[i][j] + lis(i, j + 1);
	int c2 = mat[i][j] + lis(i + 1, j + 1);
	int c3 = mat[i][j] + lis(i - 1, j + 1);

	return vis[i][j] = min(min(c1, c2), c3);
}

void build(int i, int j) {

	int ans = lis(i, j);

	int c1 = mat[i][j] + lis(i - 1, j + 1);
	int c2 = mat[i][j] + lis(i, j + 1);
	int c3 = mat[i][j] + lis(i + 1, j + 1);

	int mn = 1000, orgi = i;
	cout << i + 1;
	if (counter++ < c)
		cout << " ";

	if (ans == c1) {
		i--;
		if (i < 0)
			i = r - 1;
		mn = i;
	}

	if (ans == c2) {
		i = orgi;
		mn = min(mn, i);
	}

	if (ans == c3) {
		i = orgi;
		i++;
		if (i == r)
			i = 0;
		mn = min(mn, i);
	}
	if (++j == c)
		return;

	build(mn, j);
}
int main() {

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while (cin >> r >> c) {

		fo(i,r)
			fo(j,c)
				cin >> mat[i][j];

		int mn=1000, mni;
		fo(i,r){
			int ls = lis(i,0);
			if(mn>ls)
				mn = ls , mni=i;
		}
		build(mni, 0);
		cout << endl;
		cout << mn << endl;

		counter = 1;
		memset(vis, 0, sizeof vis);

	}

	return 0;
}
