/*
 ID: fci_isl1
 LANG: C++
 TASK: barn1
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);

	int full[205] , space[205];
	int Max,stall,cow;
	cin>>Max>>stall>>cow;

	space[0]=1;
	for(int i=0; i<cow; i++)
		cin>>full[i];

	sort(full,full+cow);

	for(int i=1; i<cow; i++)
		space[i] = full[i]-full[i-1];

	sort(space , space + cow);

	int lim = Max-1;
	int ind=cow-1;
	while(lim--){
		space[ind--]=1;
	}

	int sum =0;
	for(int i=0; i<cow; i++)
		sum += space[i];

	cout<<sum<<endl;
}
