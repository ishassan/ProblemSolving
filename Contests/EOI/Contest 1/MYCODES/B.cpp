#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

int val[10],rest[10],nbond;

long long memo[10][100000];

long long DP(int idx, int mon){
	if(idx==nbond)
		return 0;

	long long &m = memo[idx][mon];
	if(m!=-1)
		return m;

	long long no = DP(idx+1,mon);
	long long yes = (mon>=val[idx])? DP(idx, mon-val[idx])+rest[idx]: 0;

	return m = max(yes,no);

}

int main() {

	int money,year;

	cin>>money>>year>>nbond;
	fo(i,nbond){
		cin>>val[i]>>rest[i];
		val[i] /=1000;
	}
	memset(memo,-1,sizeof memo);

	long long res = money;
	while(year--)
		res += DP(0,res/1000);


	cout<<res<<endl;

	return 0;
}
