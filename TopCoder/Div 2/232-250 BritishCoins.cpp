//TC SRM 165-D2-1	Point = 237.90 of 250	time = 6m;
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
using namespace std; 

class BritishCoins {
public:
vector <int> coins(int pence)
{
	vector<int> res;
	int mod;
	mod = pence % (12 * 20);
	pence /= (12*20);
	res.push_back(pence);

	pence = mod;
	mod = pence % 12;
	pence /= 12;

	res.push_back(pence);

	res.push_back(mod);

	return res;






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
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 533; int Arr1[] = { 2,
  4,
  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, coins(Arg0)); }
	void test_case_1() { int Arg0 = 0; int Arr1[] = { 0,
  0,
  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, coins(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = { 0,
  0,
  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, coins(Arg0)); }
	void test_case_3() { int Arg0 = 4091; int Arr1[] = { 17,
  0,
  11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, coins(Arg0)); }
	void test_case_4() { int Arg0 = 10000; int Arr1[] = { 41,
  13,
  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, coins(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
BritishCoins c;
c.__test();
int i=0;
cin>>i;
return 0;
}
// END CUT HERE
