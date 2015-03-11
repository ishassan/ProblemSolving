//TC  312-D2-1		Points =222.25 of 250		Time: 6m
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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

class EsperantoNumbers {
public:

	string esper(int n) {
		switch (n) {
		//"unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek"
		case 1:
			return "unu";
		case 2:
			return "du";
		case 3:
			return "tri";
		case 4:
			return "kvar";
		case 5:
			return "kvin";
		case 6:
			return "ses";
		case 7:
			return "sep";
		case 8:
			return "ok";
		case 9:
			return "nau";
		case 10:
			return "dek";

		default:
			return "";
		}
	}

	string nameThisNumber(int x) {

		if(x<11)
			return esper(x);

		string res;
		int a = x/10;
		if(a==1)
			res = "dek";

		else
		 res = esper(a) + "dek";

		 a = x%10;

		 if(esper(a)!="")
			 res += " " + esper(a);

		 return res;
	}

	// BEGIN CUT HERE
	void __test() {
		// END CUT HERE

		// BEGIN CUT HERE
		static bool s_FirstTime = true;
		if (s_FirstTime) {
			s_FirstTime = false;
			run_test(-1);
		}
		// END CUT HERE

		// BEGIN CUT HERE
	}
	// END CUT HERE

	// BEGIN CUT HERE
public:
	void run_test(int Case) {
		if ((Case == -1) || (Case == 0))
			test_case_0();
		if ((Case == -1) || (Case == 1))
			test_case_1();
		if ((Case == -1) || (Case == 2))
			test_case_2();
		if ((Case == -1) || (Case == 3))
			test_case_3();
	}
private:
	template<typename T> string print_array(const vector<T> &V) {
		ostringstream os;
		os << "{ ";
		for (typename vector<T>::const_iterator iter = V.begin(); iter
				!= V.end(); ++iter)
			os << '\"' << *iter << "\",";
		os << " }";
		return os.str();
	}
	void verify_case(int Case, const string &Expected, const string &Received) {
		cerr << "Test Case #" << Case << "...";
		if (Expected == Received)
			cerr << "PASSED" << endl;
		else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: \"" << Expected << '\"' << endl;
			cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}
	void test_case_0() {
		int Arg0 = 1;
		string Arg1 = "unu";
		verify_case(0, Arg1, nameThisNumber(Arg0));
	}
	void test_case_1() {
		int Arg0 = 90;
		string Arg1 = "naudek";
		verify_case(1, Arg1, nameThisNumber(Arg0));
	}
	void test_case_2() {
		int Arg0 = 11;
		string Arg1 = "dek unu";
		verify_case(2, Arg1, nameThisNumber(Arg0));
	}
	void test_case_3() {
		int Arg0 = 57;
		string Arg1 = "kvindek sep";
		verify_case(3, Arg1, nameThisNumber(Arg0));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	EsperantoNumbers c;
	c.__test();
	return 0;
}
// END CUT HERE
