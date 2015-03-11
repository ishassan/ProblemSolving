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
	//freopen("in.txt","rt",stdin);
	//freopen("out.txt","wt",stdout);
	string in;
	while (getline(cin, in)) {
		fo(i,in.size()) {
			string tmp = "";
			if (in[i] == '!')
				cout << endl;
			while (isdigit(in[i])) {
				tmp += in[i];
				i++;
			}
			fo(j,tmp.size()) {
				int l = tmp[j] - '0';
				while (l--) {
					if (in[i] == 'b')
						cout << " ";
					else
						cout << in[i];
				}

			}
		}
		cout<<endl;
	}
	return 0;

}
