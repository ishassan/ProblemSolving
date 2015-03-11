#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

pair<int,int> p[11];
int main(){

	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>p[i].first>>p[i].second;

	int mn = 1<<28;
	for(int i=1; i<(1<<n); i++){
		pair<int,int> val;
		val.first=1, val.second=0;

		for(int j=0; j<n; j++){
			if(i & (1<<j)){
				val.first *= p[j].first;
				val.second += p[j].second;
			}
		}

		mn = min(mn, abs(val.first - val.second));
	}

	cout<<mn;
}
