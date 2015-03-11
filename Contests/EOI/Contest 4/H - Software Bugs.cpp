#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>
#include <cmath>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
typedef long long ll;
using namespace std;

int main() {/*
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
#endif*/

	string str;

	while(getline(cin,str)){
		int idx=0;
		while((idx=str.find("BUG",0)) != str.npos)
			str.erase(idx,3);
		cout<<str<<endl;
	}

	return 0;
}
