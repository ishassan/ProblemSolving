#include <cstring>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int x[110],y[110];

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n,p1,p2,p3,t1,t2;
	cin>>n>>p1>>p2>>p3>>t1>>t2;

	fo(i,n)
		cin>>x[i]>>y[i];

	long long res=0;
	fo(i,n-1){
		int m=y[i] - x[i];
		res += m*p1;

		m = x[i+1]-y[i];
		if(m>t1)
			res+=t1*p1;

		else{
			res +=m*p1;
			continue;
		}

		m-=t1;
		if(m>=t2)
			res += t2*p2;

		else{
			res += m*p2;
			continue;
		}
		m-=t2;

		if(m>0)
		res+= p3*m;
	}
	res += (y[n-1]-x[n-1])*p1;

	cout<<res;
	return 0;

}
