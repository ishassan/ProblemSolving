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
#define foo(i,m,n) for(int i=(m); i<(n); i++)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;



class DistanceBetweenStrings {
public:

int getDistance(string a, string b, string letterSet)
{
	int res =0;
	for(int i=0; i<letterSet.size(); i++){
		int sum1=0, sum2=0;

		for(int j=0; j<a.size(); j++)
			sum1 += (tolower(a[j])==letterSet[i]);

		for(int j=0; j<b.size(); j++)
			sum2 += (tolower(b[j]) == letterSet[i]);

		res += (sum1-sum2)*(sum1-sum2);
	}

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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; string Arg1 = "contest"; string Arg2 = "tcp"; int Arg3 = 2; verify_case(0, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "abcdef"; string Arg1 = "fedcba"; string Arg2 = "fed"; int Arg3 = 0; verify_case(1, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaaa"; string Arg1 = "bbbbb"; string Arg2 = "a"; int Arg3 = 25; verify_case(2, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaAaB"; string Arg1 = "BbaAa"; string Arg2 = "ab"; int Arg3 = 2; verify_case(3, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; string Arg1 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; string Arg2 = "ba"; int Arg3 = 5000; verify_case(4, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "ToPcOdEr"; string Arg1 = "tOpCoDeR"; string Arg2 = "wxyz"; int Arg3 = 0; verify_case(5, Arg3, getDistance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
DistanceBetweenStrings c;
c.__test();
return 0;
}
// END CUT HERE
