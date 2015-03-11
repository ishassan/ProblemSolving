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

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;

class Rounder {
public:
int round(int n, int b)
{

	int lim = 0;
	while(lim<n)
		lim+= b;

	int low = lim-b;

	if(lim-n > n-low)
		return low;
	return lim;



}
/*-------------------------------------
	int u = (n/b +1) *b;
	int d = (n/b)*b;
	return (u-n>n-d)? d:u;
*/

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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 10; verify_case(0, Arg2, round(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 10; int Arg2 = 0; verify_case(1, Arg2, round(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 3; int Arg2 = 99; verify_case(2, Arg2, round(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123456; int Arg1 = 7; int Arg2 = 123459; verify_case(3, Arg2, round(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 49; int Arg1 = 7; int Arg2 = 49; verify_case(4, Arg2, round(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
Rounder c;
c.__test();
return 0;
}
// END CUT HERE
