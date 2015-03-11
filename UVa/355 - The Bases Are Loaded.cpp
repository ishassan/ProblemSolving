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

int val(char c) {
	if (isdigit(c))
		return c - '0';
	return c - 'A' + 10;
}
char toChar(int i) {
	if (i < 10)
		return i + '0';
	return i - 10 + 'A';
}
string convert(string num, int fromBase, int toBase) {
	string neg = "";
	if (num[0] == '-') {
		neg = "-";
		num = num.substr(1);
	}
	long long temp = 0;
	long long p = 1;
	for (int i = num.size() - 1; i >= 0; i--) {
		temp += p * val(num[i]);
		p *= fromBase;
	}
	if (temp == 0)
		return "0";

	string res = "";
	while (temp > 0) {
		res += toChar(temp % toBase);
		temp /= toBase;
	}
	reverse(res.begin(), res.end());
	return neg + res;
}

int main() {

	//freopen("out.txt","w",stdout);
	int from,to;
	string num;
	while(cin>>from>>to>>num){
		bool illegal =0;
		fo(i,num.size()){
			if( (isdigit(num[i]) && num[i]-'0' >= from) || (isalpha(num[i]) && num[i]-55>=from))
			{
				cout<<num<<" is an illegal base "<<from<<" number\n";
				illegal =1;
				break;
			}
		}
		if(!illegal)
		cout<<num<<" base "<<from<<" = "<<convert(num,from,to)<<" base "<<to<<endl;
	}
	return 0;
}
