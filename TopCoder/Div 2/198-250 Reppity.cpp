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

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;

class Reppity {
public:
int longestRep(string input)
{
	//hhanger code
	int len = input.size();
	for(int l = len/2; l >0; l--){
		for(int st=0; st+l<=len; st++){
			string s = input.substr(st,l);
			if(input.find(s,st+l) != input.npos)
				return l;
		}
	}

	return 0;

}







};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
