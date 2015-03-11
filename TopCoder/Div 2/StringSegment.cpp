//srm 320-D2-1		Points:227.54 of 250
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

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class StringSegment {
public:
double average(string s)
{


	int seg =1;
	int sz = s.size();

	if(sz==1)
		return 1;

	for(int i=1; i<sz; i++){
		if(s[i]!=s[i-1])
			seg++;
	}

	return (double)sz/seg;


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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaabbaaac"; double Arg1 = 2.25; verify_case(0, Arg1, average(Arg0)); }
	void test_case_1() { string Arg0 = "aabbccdd"; double Arg1 = 2.0; verify_case(1, Arg1, average(Arg0)); }
	void test_case_2() { string Arg0 = "abba"; double Arg1 = 1.3333333333333333; verify_case(2, Arg1, average(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
StringSegment c;
c.__test();
return 0;
}
// END CUT HERE
