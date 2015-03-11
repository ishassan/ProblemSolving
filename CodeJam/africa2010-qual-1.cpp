#include<iostream>
#include <stdio.h>
#include<sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;



int main() {
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int N;
	cin >> N;

	for (int x = 1; x <= N; ++x) {
		printf("Case #%d: ", x);
		pair<int,int> arr[2010];
		int sz=0;
		int m,l,val;
		cin>>m>>l;
		for (int i = 1; i <= l; ++i) {
			cin>>val;
			arr[sz++] = make_pair(val,i);
		}
		sort(arr,arr+sz);
		int ind=sz;
		for (int i = 0; i < sz; ++i) {
			if(arr[i].first > m){
				ind = i;
				break;
			}
		}

		for (int i = 0; i < ind; ++i) {
			for (int j = i+1; j < ind; ++j) {
				if(arr[i].first + arr[j].first == m){
					cout<<min(arr[i].second,arr[j].second)<<" ";
					cout<<max(arr[i].second,arr[j].second)<<endl;
					goto end;
				}
			}
		}
		end:;
	}
	return 0;
}
