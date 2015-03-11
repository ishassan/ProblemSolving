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

string str;
int getLastSame(int idx) {
	char ch = str[idx];
	while (++idx < sz(str) && str[idx] == ch)
		;
	return idx - 1;
}

int getLastUnique(int idx) {
	char ch = str[idx];
	while (++idx < sz(str) && str[idx] != ch)
		ch = str[idx];

	if (str[idx] != ch)
		return idx - 1;
	return idx - 2;
}
int main() {

	while (getline(cin, str)) {
		string res;
		for (int i = 0; i < sz(str); ++i) {
			int idx = getLastSame(i);
			if (idx > i) {
				int cnt = idx + 1 - i;
				while (cnt > 9)
					res += "9", res += str[i], cnt -= 9;
				if (cnt == 1)
					res += "1", res += str[i], res += "1";
				else
					res += (cnt + '0'), res += str[i];
				i = idx;
				continue;
			}
			idx = getLastUnique(i);
			res += "1";
			repe(ii,i,idx)
				if (str[ii] == '1')
					res += "11";
				else
					res += str[ii];

			res += "1";
			i = idx;
		}
		printf("%s\n", res.c_str());
	}
	return 0;
}
