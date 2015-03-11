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
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

string newPlate = "BDEFGHJKLNOQRSTUVWXYZ";
int Map[300];

string boy, girl;
int c;
int lastOld;

int encodeOld(string str) {
	int p = 1;
	int res = 0;

	for (int i = 6; i >= 3; --i) {
		res += (str[i] - '0') * p;
		p *= 10;
	}

	for (int i = 2; i >= 0; --i) {
		res += (str[i] - 'A') * p;
		p *= 26;
	}

	return res;
}

int encodeNew(string str) {
	int p = 1;
	int res = 0;

	for (int i = 6; i >= 5; --i) {
		res += (str[i] - '0') * p;
		p *= 10;
	}

	for (int i = 4; i >= 0; --i) {
		res += Map[str[i]] * p;
		p *= sz(newPlate);
	}

	return res + lastOld;
}

bool isOld(string str) {
	return (isdigit(str[3]) && isdigit(str[4]));
}

bool isNew(string str) {
	rep(i,5)
		if (str[i] == 'A' || str[i] == 'C' || str[i] == 'M' || str[i] == 'I'
				|| str[i] == 'P')
			return false;

	return (isalpha(str[3]) && isalpha(str[4]));
}


int main() {

	rep(i,sz(newPlate)) {
		Map[newPlate[i]] = i;
	}

	lastOld = encodeOld("ZZZ9999") + 1;
	while (cin >> boy >> girl >> c) {
		if (boy == "*" && girl == "*" && c == 0)
			return 0;

		int nboy, ngirl;

		if (isOld(girl))
			ngirl = encodeOld(girl);
		else if (isNew(girl))
			ngirl = encodeNew(girl);
		else {
			cout << "N\n";
			continue;
		}

		if (isOld(boy))
			nboy = encodeOld(boy);
		else
			nboy = encodeNew(boy);

		if (ngirl > nboy && ngirl <= (nboy + c))
			cout << "Y\n";
		else
			cout << "N\n";

	}

	return 0;
}
