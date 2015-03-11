#include<iostream>
#include <stdio.h>
#include<sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	//freopen("out.txt","w",stdout);
	int N;
	string str;
	cin >> N;
	getline(cin, str);

	map<char,string> key;
	key['a'] = "2";
	key['b'] = "22";
	key['c'] = "222";
	key['d'] = "3";
	key['e'] = "33";
	key['f'] = "333";
	key['g'] = "4";
	key['h'] = "44";
	key['i'] = "444";
	key['j'] = "5";
	key['k'] = "55";
	key['l'] = "555";
	key['m'] = "6";
	key['n'] = "66";
	key['o'] = "666";
	key['p'] = "7";
	key['q'] = "77";
	key['r'] = "777";
	key['s'] = "7777";
	key['t'] = "8";
	key['u'] = "88";
	key['v'] = "888";
	key['w'] = "9";
	key['x'] = "99";
	key['y'] = "999";
	key['z'] = "9999";
	key[' '] = "0";

	for (int x = 1; x <= N; ++x) {
		printf("Case #%d: ", x);
		getline(cin,str);
		string res;
		for (int i = 0; i < str.size(); ++i) {
			if(i && key[str[i]][0]==res[res.size()-1])
				res+=" ";
			res+=key[str[i]];
		}
		cout<<res<<endl;
	}
	return 0;
}
