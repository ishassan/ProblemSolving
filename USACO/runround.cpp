/*
 ID: fci_isl1
 LANG: C++
 TASK: runround
 */
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
typedef unsigned long ul;

bool vis[10];
int digits[10];
void mem(){
	for(int i=0; i<10; i++)
		vis[i] =0,digits[i]=0;
}

bool isfinish(short sz){
	for(int i=0; i<sz; i++)
		if(vis[i]==0)
			return 0;
	return 1;
}
bool isrun(vector<short>& num){
	short sz = num.size(), szz = sz;

	if(sz==1)
		return 1;

	for(int i=0; i<sz; i++)
		if(num[i]==0)
			return 0;
	for(int i=0; i<10; i++)
		if(digits[i]>1)
			return 0;

	short ind =0;
	while(szz--){
		short chk = (ind + num[ind]) % sz;
		if(vis[chk])
			return 0;
		vis[chk] =1;
		ind = chk;
	}

	return isfinish(sz);
}

vector<short> divide(ul num){
	vector<short> v;
	while(num>0){
		v.push_back(num%10);
		digits[num%10]++;
		num /=10;
	}

	reverse(v.begin(), v.end());

	return v;
}

void print(vector<short>& v){
	int sz = v.size();
	for(int i=0; i<sz; i++)
		cout<<v[i];
	cout<<endl;
}
int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);


	ul num;
	cin>>num;

	while(num++){
		mem();
		vector<short> v = divide(num);
		if(isrun(v)){
			print(v);
			return 0;
		}
	}

	return 0;
}
