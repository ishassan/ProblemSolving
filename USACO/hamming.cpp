/*
 ID: fci_isl1
 LANG: C++
 TASK: hamming
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int n, b, d;
int dist(int n1, int n2) {
	int res = 0;
	int diff = n1 ^ n2;
	while (diff > 0) {
		res += (diff & 1);
		diff = diff >> 1;
	}
	return res;
}

bool isvalid(int num, vector<int>& v) {
	int s = v.size();

	for (int i = 0; i < s; i++)
		if (dist(num, v[i]) < d)
			return 0;
	return 1;
}

int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);

	cin >> n >> b >> d;
	int lim = 1 << b;

	vector<int> v;

	for (int i = 0; i < lim; i++) {
		if (isvalid(i, v)){
			v.push_back(i),n--;
			if(n==0)
				break;
		}
	}

	int sz = v.size(),count = 0;

	for(int i=0; i<sz; i++){
		cout<<v[i];
		if(++count%10==0 && i+1<sz)
			cout<<endl;

		else if(i+1<sz)
			cout<<" ";
	}

	cout<<endl;
	return 0;
}
