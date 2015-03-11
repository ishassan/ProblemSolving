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

bool isprime(int n){
	if(n==2)
			return 1;

	if(n<2 || n%2==0)
		return 0;

	for(int i=2; i*i<=n; i++){
		if(n%i==0)
			return 0;

	}
	return 1;
}
int main() {

	int a,b;
	int ret=0;
	while(cin>>a>>b){
		ret =0;
		for(int i=a; i<=b; i++){
			if(isprime(i))
				ret++;
		}
		cout<<ret<<endl;
	}

	return 0;
}
