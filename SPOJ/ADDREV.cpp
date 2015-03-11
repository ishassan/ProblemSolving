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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define SZ(a) a.size()
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int main() {

	int tst;
	cin>>tst;
	while(tst--){
		string a,b;
		cin>>a>>b;
		reverse(be(a));
		reverse(be(b));

		sstr ss(a),ss2(b);
		int aa,bb;
		ss>>aa;
		ss2>>bb;
		aa += bb;
		sstr ss3;
		ss3<<aa;
		ss3>>a;reverse(be(a));
		sstr ss4(a);
		ss4>>aa;
		cout<<aa<<endl;
	}
	return 0;
}
