#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
typedef long long ll;
using namespace std;

vector<pair<pii, int> > calc;
vs names;

bool istaxi(string str) {
	if (str[0] == str[1] && str[1] == str[3] && str[3] == str[4]
			&& str[4] == str[6] && str[6] == str[7])
		return 1;
	return 0;
}
bool ispizza(string str) {
	if (str[0] > str[1] && str[1] > str[3] && str[3] > str[4] && str[4] > str[6]
			&& str[6] > str[7])
		return 1;
	return 0;
}
int main() {

	int nf, nn;
	int mxt = 0, mxp = 0, mxg = 0;
	cin >> nf;
	string name;
	calc.resize(nf);
	names.resize(nf);
	rep(i,nf) {
		cin >> nn >> name;
		names[i] = name;
		calc[i] = mp(mp(0,0),0);
		rep(j,nn) {
			cin >> name;
			if (istaxi(name)) {
				mxt = max(mxt, ++calc[i].first.first);
			} else if (ispizza(name)) {
				mxp = max(mxp, ++calc[i].first.second);
			} else {
				mxg = max(mxg, ++calc[i].second);
			}
		}
	}
	vs rt, rp, rg;
	rep(i,nf) {
		if (calc[i].first.first == mxt)
			rt.push_back(names[i]);
		if (calc[i].first.second == mxp)
			rp.push_back(names[i]);
		if (calc[i].second == mxg)
			rg.push_back(names[i]);
	}
	cout << "If you want to call a taxi, you should call: ";
	string pr = "";
	rep(i,sz(rt)) {
		cout << pr << rt[i];
		pr = ", ";
	}
	cout << ".\n";
	cout << "If you want to order a pizza, you should call: ";
	pr = "";
	rep(i,sz(rp)) {
		cout << pr << rp[i];
		pr = ", ";
	}
	cout << ".\n";
	cout
			<< "If you want to go to a cafe with a wonderful girl, you should call: ";
	pr = "";
	rep(i,sz(rg)) {
		cout << pr << rg[i];
		pr = ", ";
	}
	cout << ".";

	return 0;
}
