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
typedef unsigned long long ull;

ull toDec(string num, int base){
    ull res=0;
    ull p=1;
    for(int i=num.size()-1;i>-1;i--)
    {
        res+=p*(num[i]-'0');
        p*=base;
    }
    return res;

}
string toBase(ull dec,int to){
	if(dec==0)
		return "0";

    string res="";
    char c;
    while(dec>0)
    {
    	c = (dec%to)+'0';
        res=c + res;
        dec/=to;
    }

    return res;
}
ull mod(string num1, ull num2, int base) {


	ull s = 0;
	fo(i,num1.size()) {
		s *= base;
		s += (num1[i] - '0');
		s %= num2;
	}

	return s;
}
int main() {

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int b;
	string p,m;

	while (cin >> b) {
		if (b == 0)
			return 0;
		cin >> p >> m;


		if(p==m ||p=="0"){
			cout<<0<<endl;
			continue;
		}
		ull im = toDec(m,b);
		ull s = mod(p,im,b);
		cout<<toBase(s,b)<<endl;


	}

	return 0;
}
