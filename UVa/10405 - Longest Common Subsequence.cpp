//UVa 10405
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

const int MAX = 10000;
int sz1,sz2;
string str1,str2;
int memo[MAX][MAX];

int lcs(int i, int j) {   //how many common elements(return max common)
	//i loops on 1st squence, j loops on 2nd sequence
    if(i >= sz1 || j >= sz2)	return 0;

    if(memo[i][j] != -1)
    	return memo[i][j];

	int c1 = lcs(i+1, j);	// ignore i;
	int c2 = lcs(i, j+1);	//ignore j
	int c3 = lcs(i+1, j+1) + (str1[i] == str2[j]);	// if a[i] = b[j], then we have matching

	return memo[i][j] = max(c1, max(c2, c3));
}

int main() {

	while(getline(cin,str1) , getline(cin,str2)){
		sz1 = str1.size();
		sz2 = str2.size();

		fo(i,sz1)
			fo(j,sz2)
				memo[i][j]= -1;


		cout<<lcs(0,0)<<endl;
	}

	return 0;
}

