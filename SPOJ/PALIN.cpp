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
typedef long long ll;
using namespace std;

string str;

void nxt(int idx) {
	if (idx == -1) {
		str = "1" + str;
		return;
	}

	if (++str[idx] > '9') {
		str[idx] = '0';
		nxt(idx - 1);
	}

}
int main() {

	int tst;
	scanf("%d", &tst);

	while (tst--) {

		bool digit = false;
		cin >> str;

		if (sz(str) == 1 && str[0] < '9')
			digit = true;
		nxt(sz(str) - 1);

		if (digit) {
			cout << str << endl;
			continue;
		}

		bool change = false;
		rep(i,sz(str)/2) {
			int j = sz(str) - i - 1;
			if (str[i] == str[j])
				continue;

			change = true;
			if (str[j] < str[i])
				str[j] = str[i];
			else {
				str[j] = str[i];
				nxt(j - 1);
				--i;
			}

		}

		cout << str << endl;
	}

	return 0;
}
