#include <cstring>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	bool f = 0, bk = 0;
	string str, a, b;
	cin >> str >> a >> b;

	int pos = str.find(a, 0);
	if (pos == str.npos)
		goto g;


	pos = str.find(b,pos+a.size());
	if (pos != str.npos)
		f = 1;

	g:
	reverse(str.begin(), str.end());


	pos = str.find(a, 0);
	if (pos == str.npos) {
		if (f)
			cout << "forward\n";
		else
			cout << "fantasy\n";
		return 0;
	}

	pos = str.find(b,pos+a.size());
	if (pos != str.npos)
		bk =1;

	if(f && bk)
		cout<<"both\n";
	else if(f)
		cout<<"forward\n";
	else if(bk)
		cout<<"backward\n";
	else
		cout<<"fantasy\n";
	return 0;

}
