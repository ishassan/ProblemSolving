#include<iostream>
#include <stdio.h>
#include<sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	//freopen("out.txt","w",stdout);
	int N;
	string str;
	cin>>N;
	getline(cin,str);
	for (int x = 1; x <= N; ++x) {
		printf("Case #%d: ",x);
		vector<string> v;
		string tmp;
		getline(cin,str);
		stringstream ss(str);
		while(ss>>tmp){
			v.push_back(tmp);
		}
		for (int i = v.size()-1; i > 0; i--) {
			cout<<v[i]<<" ";
		}
		if(!v.empty())
		cout<<v[0]<<endl;
	}
	cout<<endl;
	return 0;
}
