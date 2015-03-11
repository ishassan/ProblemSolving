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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

class SumsOfPerfectPowers {
public:
	int howMany(int lowerBound, int upperBound) {
		vi perm;
		perm.push_back(0);
		perm.push_back(1);
		int res = 0;
		for (int i = 2; i * i <= upperBound; i++) {

			int p = i;
			while ((long long) p * i <= (long long) upperBound) {
				p *= i;
				perm.push_back(p);
			}

		}

		vector<bool> vb(upperBound+1, 0);
		for (int i = 0; i < perm.size(); i++)
			for (int j = i; j < perm.size(); j++)
				if (perm[i] + perm[j] <= upperBound)
					vb[perm[i] + perm[j]] = 1;

		for (int i = lowerBound; i <= upperBound; i++)
			res += vb[i];

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
		if ((Case == -1) || (Case == 4))
			test_case_4();
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
	void verify_case(int Case, const int &Expected, const int &Received) {
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
		int Arg0 = 0;
		int Arg1 = 1;
		int Arg2 = 2;
		verify_case(0, Arg2, howMany(Arg0, Arg1));
	}
	void test_case_1() {
		int Arg0 = 5;
		int Arg1 = 6;
		int Arg2 = 1;
		verify_case(1, Arg2, howMany(Arg0, Arg1));
	}
	void test_case_2() {
		int Arg0 = 25;
		int Arg1 = 30;
		int Arg2 = 5;
		verify_case(2, Arg2, howMany(Arg0, Arg1));
	}
	void test_case_3() {
		int Arg0 = 103;
		int Arg1 = 103;
		int Arg2 = 0;
		verify_case(3, Arg2, howMany(Arg0, Arg1));
	}
	void test_case_4() {
		int Arg0 = 1;
		int Arg1 = 100000;
		int Arg2 = 33604;
		verify_case(4, Arg2, howMany(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	SumsOfPerfectPowers c;
	c.__test();
	return 0;
}
// END CUT HERE
