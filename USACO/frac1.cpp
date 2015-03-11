/*
 ID: fci_isl1
 LANG: C++
 TASK: frac1
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define mp(a,b) make_pair(a,b)
double vis[8000]={0};
int size = 1;

bool found(double res){
	for(int i=0;i<size; i++)
		if(fabs(vis[i]-res) < 1e-9)
			return 1;
	return 0;
}
int main() {
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);

	int n;
	scanf("%d",&n);

	vector<pair<double,string> > v;
	v.push_back( mp(0,"0/1") );

	for(int i=1; i<=n; i++)	//denom
		for(int j=1; j<i; j++){ //num
			double res = (double)j/i;
			if(!found(res)){
				stringstream ss;
				ss<<j<<"/"<<i;
				v.push_back( mp(res,ss.str()) );
				vis[size++] = res;
			}
		}

	sort(v.begin(), v.end());
	v.push_back( mp(1,"1/1") ), size++;

	for(int i=0; i<size; i++)
		cout<<v[i].second<<endl;

	return 0;
}
