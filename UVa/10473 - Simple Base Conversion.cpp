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


int main() {


	string input;
	while(cin>>input){
		if(input[0]=='-')
			return 0;

		stringstream ss;
		if(input.size()>2 && input.substr(0,2)=="0x")
		{

			ss<<dec<<input;
			 int res;
			 ss>>hex>>res;
			 cout<<res<<endl;

		}

		else{

			int num;
			string res;
			ss<<input;
			ss>>num;
			ss.clear();
			ss<<hex<<num;
			ss>>dec>>res;

			fo(i,res.size())
				if(islower(res[i]))
					res[i]=toupper(res[i]);

			res = "0x" + res;
			cout<<res<<endl;
		}

	}
	return 0;
}
