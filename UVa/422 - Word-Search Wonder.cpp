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

#define fo(i,n) for(i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;


pair<int, int> search(int r, int c, string dest, vs& mat) {
	int sq = mat.size();
	int sz = dest.size();
	int i;
	int lim = sz - 1;

	//Check Down
	if (r + lim < sq) {

		fo(i,sz) { //original diriction
			if (mat[r + i][c] != dest[i])
				break;
		}
		if (i == sz) //reaches the end of loop
			return make_pair(r + lim, c);

		if (c + lim < sq) { //right diagonal
			fo(i,sz) {
				if (mat[r + i][c + i] != dest[i])
					break;
			}
			if (i == sz)
				return make_pair(r + lim, c + lim);
		}

		if (c - lim > -1) { //left diagonal
			fo(i,sz) {
				if (mat[r + i][c - i] != dest[i])
					break;
			}
			if (i == sz)
				return make_pair(r + lim, c - lim);
		}
	}

	//Check Up
	if (r - lim > -1) {

		fo(i,sz) { //original
		 if (mat[r - i][c] != dest[i])
		 break;
		 }
		 if (i == sz)
		 return make_pair(r-lim,c);

		if (c + lim < sq) { //right diagonal
			fo(i,sz) {
				if (mat[r - i][c + i] != dest[i])
					break;
			}
			if (i == sz)
				return make_pair(r - lim, c + lim);
		}

		if (c - lim > -1) { //left diagonal
			fo(i,sz) {
				if (mat[r - i][c - i] != dest[i])
					break;
			}
			if (i == sz)
				return make_pair(r - lim, c - lim);
		}
	}

	//Check Right
	if (c + lim < sq) {
		fo(i,sz) {

			if (mat[r][c + i] != dest[i])
				break;
		}
		if (i == sz)
			return make_pair(r, c + lim);

	}

	//Check Left
	if (c - lim > -1) {
		fo(i,sz) {

			if (mat[r][c - i] != dest[i])
				break;
		}
		if (i == sz)
			return make_pair(r, c - lim);
	}
	return make_pair(-1, -1);
}

int main() {


	int sq;
	cin >> sq;
	vs mat(sq);
	int i, j;
	fo(i,sq) {
		cin >> mat[i];
	}

	while (1) {
		start:
		string input;
		cin >> input;
		if (input == "0")
			break;

		bool found = 0;
		fo(i,sq) {
			fo(j,sq) {
				pair<int, int> p = search(i, j, input, mat);
				if (p.first != -1) {
					cout << i + 1 << "," << j + 1 << " " << p.first + 1 << ","
							<< p.second + 1;
					found = 1;
					goto end;
				}

			}
		}
		end: if (!found)
			cout << "Not found";
		cout << endl;
	}
	return 0;
}
