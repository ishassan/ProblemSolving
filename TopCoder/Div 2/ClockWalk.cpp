//TC 175 -D2-1		Points = 242  of 250(WA,AC now)		Time: 6m
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

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class ClockWalk {
public:
int finalPosition(string flips)
{

	int ret=0;
	fo(i,flips.size()){
		if(flips[i]=='h')
			ret += i+1;

		else
			ret -= i+1;
	}

	if(ret%12==0)
		return 12;

	if(ret < 0)
		return 12 + (ret%12);

	return ret%12;





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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hhthh"; int Arg1 = 9; verify_case(0, Arg1, finalPosition(Arg0)); }
	void test_case_1() { string Arg0 = "hhtht"; int Arg1 = 11; verify_case(1, Arg1, finalPosition(Arg0)); }
	void test_case_2() { string Arg0 = "hthth"; int Arg1 = 3; verify_case(2, Arg1, finalPosition(Arg0)); }
	void test_case_3() { string Arg0 = "hthhhhh"; int Arg1 = 12; verify_case(3, Arg1, finalPosition(Arg0)); }
	void test_case_4() { string Arg0 = "hthhthtththhtttthttthhhthtttthh"; int Arg1 = 6; verify_case(4, Arg1, finalPosition(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
ClockWalk c;
c.__test();
return 0;
}
// END CUT HERE
