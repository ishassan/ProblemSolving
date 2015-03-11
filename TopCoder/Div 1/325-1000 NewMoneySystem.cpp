#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)
#define all(arr) arr.begin(),arr.end()

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;
typedef long long ll;

class NewMoneySystem {
public:
	map<pair<int,ll>,ll > m;

	ll dp(int k, ll remain){
		if(k==1)
			return remain;
		pair<int,ll> p = make_pair(k,remain);
		if(m.count(p))
			return m[p];

		ll res = dp(k-1, remain/2) + remain%2;

		for (int i = 3; i < 6; ++i)
			res = min(res , dp(k-1, remain/i)+remain%i);

		return m[p] = res;
	}
long long chooseBanknotes(string N, int K)
{
	ll n;
	stringstream ss(N);
	ss>>n;
	m.clear();
	return dp(K,n);


}



// BEGIN CUT HERE
void __test()
{
// END CUT HERE

// BEGIN CUT HERE
		static bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }
// END CUT HERE

// BEGIN CUT HERE
}
// END CUT HERE

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1025"; int Arg1 = 6; long long Arg2 = 2LL; verify_case(0, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1005"; int Arg1 = 5; long long Arg2 = 3LL; verify_case(1, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "12000"; int Arg1 = 14; long long Arg2 = 1LL; verify_case(2, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "924323565426323626"; int Arg1 = 1; long long Arg2 = 924323565426323626LL; verify_case(3, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "924323565426323626"; int Arg1 = 50; long long Arg2 = 10LL; verify_case(4, Arg2, chooseBanknotes(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
NewMoneySystem c;
c.__test();
return 0;
}
// END CUT HERE
