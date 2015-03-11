#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int seg[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
//int ans[21]={0,0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,

ll tostk(int num) {
	ll res = 0;
	while (num) {
		res += seg[num % 10];
		num /= 10;
	}
	return res;
}
string getMax(int nstk) {
	string res;
	int lim = nstk / 2 - 1;
	fo(i,lim)
		res += "1";
	if (nstk % 2 == 0)
		res += "1";
	else
		res = "7" + res;
	return res;
}

string getMin(int nstk) {
	map<ll, ll> ans; //ans[stk]=num
	stringstream ss;
	ll s;

	for (ll i = 1; i <= 10000; i++) {
		s = tostk(i);
		if (ans.find(s) != ans.end())
			ans[s] = min(ans[s], i);
		else
			ans[s] = i;
	}
	if(ans.find(nstk) != ans.end()){
		ss<<ans[nstk];
		return ss.str();
	}

	string res;
	while(ans.find(nstk) == ans.end()){
		res += "8";
		nstk -= 7;
	}

	ss<<ans[nstk];
	return ss.str()+res;
}
int main() {

	int nstk;
	cin >> nstk;

	cout << getMin(nstk) << " " << getMax(nstk) << endl;
	return 0;
}
