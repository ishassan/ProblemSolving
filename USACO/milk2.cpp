/*
	 ID: fci_isl1
	 LANG: C++
	 PROB: milk2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	freopen("milk2.in", "r", stdin);
	freopen("milk2.out","w",stdout);

	int n;
	cin>>n;

	vector<pair<int,int> > v(n);

	int yes=0,no=0,val;
	for(int i=0; i<n; i++){
		cin>>v[i].first>>v[i].second;

		if(yes < (val = v[i].second - v[i].first))
			yes = val;
	}

	if(n==0){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	if(n==1){
		cout<<v[0].second - v[0].first<<" "<<0<<endl;
		return 0;
	}

	sort(v.begin(),v.end());


	for(int i=1; i<n; i++){
		if(v[i].first>v[i-1].second){
			if(no < (val = (v[i].first - v[i-1].second)))
				no = val;
		}

		else
		{
			v[i-1].second = max(v[i].second , v[i-1].second);
			if(yes < (val = v[i-1].second - v[i-1].first))
				yes = val;
			v.erase(v.begin()+i);
			i--,n--;
		}

	}

	cout<<yes<<" "<<no<<endl;
	return 0;
}
