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

#define val(c) ((c=='T')?true:false)

string getExpr(string expr, int idx) {
	int cnt = 0;
	reps(i,idx,sz(expr)) {
		if (expr[i] == '(')
			cnt++;
		else if (expr[i] == ')') {
			cnt--;
			if (cnt == 0)
				return expr.substr(idx+1, i - (idx+1));
		}
	}

	return "ERROR";
}
bool parse(string expr, bool And) {

	bool res = And;

	rep(i,sz(expr)) {
		if (expr[i] == 'F' || expr[i] == 'T') {
			if (And)
				res = res && val(expr[i]);
			else
				res = res || val(expr[i]);
		}

		else if (expr[i] == '(') {
			string subex = getExpr(expr, i);
			bool ret = parse(subex, !And);

			if (And)
				res = res && ret;
			else
				res = res || ret;

			i += sz(subex)+1;
		}
	}

	return res;
}
int main() {

	string expr;
	int tst = 1;

	while (cin >> expr) {
		expr.erase(0, 1);
		expr.erase(sz(expr) - 1, 1);

		if (expr == "")
			return 0;

		int cnt = 0, mx = 0;
		rep(i,sz(expr)) {
			if (expr[i] == '(')
				mx = max(mx, ++cnt);
			else if (expr[i] == ')')
				cnt--;
		}

		printf("%d. ", tst++);

		cout << (parse(expr, mx % 2 == 0) ? "true" : "false") << endl;
	}

	return 0;
}
