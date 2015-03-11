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
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class BlackAndRed {
public:
int cut(string deck)
{

	int ind=0, b=0, small = 0;
	fo(i,deck.size()){
		b += (deck[i]=='B')? 1: -1;
		if(b<small)
			ind = i+1, small = b;
	}
	return ind;


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
	void test_case_0() { string Arg0 = "BRBRBR"; int Arg1 = 0; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { string Arg0 = "RBRBRB"; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { string Arg0 = "BBBRRRRB"; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { string Arg0 = "BR"; int Arg1 = 0; verify_case(3, Arg1, cut(Arg0)); }
	void test_case_4() { string Arg0 = "RBRBBRRRRBBBRBBRRBRBBRRRBRBBBRBRBRBRBRRB"; int Arg1 = 9; verify_case(4, Arg1, cut(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
BlackAndRed c;
c.__test();
return 0;
}
// END CUT HERE
