#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

unsigned int powr(unsigned int a,unsigned int b){
	if(b==0)
		return 1;

	unsigned int ret =1;
	fo(i,b)
		ret *= a;

	return ret;
}
int main() {

	string n;
	while(cin>>n){
		int sz = n.size();
		unsigned int ret =0;
		fo(i,n.size()){
			ret += (n[i]-'0')*(powr(2,sz--) -1);
		}
		cout<<ret<<endl;
	}

	return 0;
}
