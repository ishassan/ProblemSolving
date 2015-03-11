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
#define foo(i,m,n) for(int i=(m);i<(n);++i)
#define all(arr) arr.begin(),arr.end()

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef stringstream sstr;

class ShorterSuperSum {
public:
	int arr[20][20];
	int rec(int k,int n){
		if(k==0)
			return n;

		if(arr[k][n] != -1)
			return arr[k][n];

		int res=0;
		foo(i,1,n+1){
			res += rec(k-1,i);
		}

		return arr[k][n] = res;
	}
	int calculate(int k, int n) {
		memset(arr,-1,sizeof arr);
		return rec(k,n);
	}

};

