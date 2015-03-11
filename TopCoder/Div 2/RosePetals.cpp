//TC 315-D2-1 	Points = 228.61 of 250   Time = 5 m
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

class RosePetals {
public:

	int petals(int dice) {

		switch (dice) {
		case 3:
			return 2;

		case 5:
			return 4;

		default:
			return 0;

		}
	}

	int getScore(vector<int> dice) {

		int sum = 0;

		for(int i=0; i<dice.size(); i++){

			sum += petals(dice[i]);
		}

		return sum;
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
		int Arr0[] = { 1, 2, 3, 2, 1 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 2;
		verify_case(0, Arg1, getScore(Arg0));
	}
	void test_case_1() {
		int Arr0[] = { 4, 4, 5, 6, 5 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 8;
		verify_case(1, Arg1, getScore(Arg0));
	}
	void test_case_2() {
		int Arr0[] = { 1, 2, 3, 3, 5 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 8;
		verify_case(2, Arg1, getScore(Arg0));
	}
	void test_case_3() {
		int Arr0[] = { 3, 3, 3, 3, 3 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 10;
		verify_case(3, Arg1, getScore(Arg0));
	}
	void test_case_4() {
		int Arr0[] = { 2, 2, 2, 2, 2 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 0;
		verify_case(4, Arg1, getScore(Arg0));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	RosePetals c;
	c.__test();
	return 0;
}
// END CUT HERE
