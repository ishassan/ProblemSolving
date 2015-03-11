//TC 201-D2-1		Points = 249.41 of 250	10-20 sec
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

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class Multiples {
public:
int number(int min, int max, int factor)
{

	int res=0;
	for(int i =min; i<=max; i++)
		if(i%factor==0)
			res++;

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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 14; int Arg2 = 5; int Arg3 = 3; verify_case(0, Arg3, number(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 24; int Arg2 = 3; int Arg3 = 6; verify_case(1, Arg3, number(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = -123456; int Arg1 = 654321; int Arg2 = 997; int Arg3 = 780; verify_case(2, Arg3, number(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = -75312; int Arg1 = 407891; int Arg2 = 14; int Arg3 = 34515; verify_case(3, Arg3, number(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
Multiples c;
c.__test();
return 0;
}
// END CUT HERE
