#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

int main() {

	int n;
	cin>>n;

	int t,s,tt,ss;
	cin>>t>>s;

	s+=t;
	int mx =0;
	fo(i,n-1){
		cin>>tt>>ss;
		if(s>tt)
			mx = max(mx,s-tt);

		t = max(s,tt);
		s = t+ss;
	}

	cout<<mx<<endl;
	return 0;
}
