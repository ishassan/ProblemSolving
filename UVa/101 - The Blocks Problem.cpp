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

int n;
int mat[25][25];
int sizes[25] = { 0 };

void srch(int target, int& r, int& c) {
	fo(i,n) {
		fo(j,sizes[i]) {
			if (mat[j][i] == target) {
				r = j, c = i;
				return;
			}
		}
	}
}

void init(int r, int c) {

	int num, sz;
	int red = 0;
	foo(i,r+1,sizes[c]) {
		num = mat[i][c];
		sz = sizes[num];
		mat[i][c] = -1;
		mat[sz][num] = num;
		sizes[num]++, red++;
	}

	sizes[c] -= red;
}
int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin >> n;
	string o1, o2;
	int a, b;
	fo(i,n)
		mat[0][i] = i;

	fo(i,n)
		sizes[i] = 1;

	while (cin >> o1) {
		if (o1 == "quit")
			break;

		cin >> a >> o2 >> b;

		//Check validity
		if (a == b)
			continue;

		int r1, c1, r2, c2;

		srch(a, r1, c1);
		srch(b, r2, c2);

		fo(i,sizes[c1])
			if (mat[i][c1] == b)
				goto end;

		fo(i,sizes[c2])
			if (mat[i][c2] == a)
				goto end;

		//Code Core
		if (o1 == "move")
			init(r1, c1);

		if (o2 == "onto")
			init(r2, c2);

		int sz1,sz2;
		sz1 = sizes[c1];
		sz2 = sizes[c2];
		foo(i,r1,sz1) {
			mat[sz2++][c2] = mat[i][c1];
			mat[i][c1] = -1;
			sizes[c1]--;
			sizes[c2]++;
		}

		end: ;
	}
	fo(i,n) {
		cout << i << ":";
		fo(j,sizes[i]) {
			cout << " " << mat[j][i];
		}
		cout << endl;
	}

	return 0;
}
