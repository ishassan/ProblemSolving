/*
  ID: fci_isl1
  LANG: C++
  PROG: gift1
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

int main() {

	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

	int NP;
	cin>>NP;
	map<string,int> m;
	vector<string> n(NP);
	string name;
	fo(i,NP)
	{
		cin>>name;
		m[name]=0;
		n[i]=name;
	}

	fo(i,NP){
		int money,num,val;
		cin>>name>>money>>num;
		if(money ==0 || num==0)
			continue;

		val = money/num;
		m[name] -= val * num;

		while(num--){
			cin>>name;
			m[name] += val;
		}
	}

	fo(i,NP){
		cout<<n[i]<<" "<<m[n[i]]<<endl;
	}
	return 0;
}
