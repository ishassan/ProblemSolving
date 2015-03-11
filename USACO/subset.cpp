/*
 ID: fci_isl1
 LANG: C++
 TASK: subset
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int n;
int memo[40][781];

#define fo(a,b) for(int a=0; a<b; a++)

int DP(int ind, int sum){
	int &m = memo[ind][sum];
	if(sum==0)
		return m=1;

	if(sum <0)
		return m=0;

	if(m != -1)
		return m;

	int count =0;
	for(int i=ind+1; i<=n; i++)
		count += DP(i,sum-i);

	return m = count;

}
void mem(){
	for(int i=0; i<n; i++)
		for(int j=0; j<781; j++)
			memo[i][j] = -1;

}
int main() {
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	cin>>n;
	int all = (n*(n+1)) / 2;

	if(all%2==1){
		cout<<0<<endl;
		return 0;
	}
	mem();
	int value = all/2;

	cout<<DP(1,value) << endl;
	return 0;
}
