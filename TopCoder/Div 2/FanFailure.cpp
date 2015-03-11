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
#define all(arr) arr.begin(),arr.end()

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef stringstream sstr;

class FanFailure {
public:
	vector<int> getRange(vector<int> cap, int minCooling) {

		int sz = cap.size();
		sort( all(cap));

		vi res(2, 0);
		int count = 0;

		for (int i = sz - 1; i > -1; i--) {
			if (count >= minCooling)
				break;
			count += cap[i], res[0]++;
		}
		res[0] = sz - res[0];
		count = 0;
		fo(i,sz) {
			if (count >= minCooling)
				break;
			count += cap[i], res[1]++;
		}

		res[1] = sz - res[1];
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
	void verify_case(int Case, const vector<int> &Expected,
			const vector<int> &Received) {
		cerr << "Test Case #" << Case << "...";
		if (Expected == Received)
			cerr << "PASSED" << endl;
		else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: " << print_array(Expected) << endl;
			cerr << "\tReceived: " << print_array(Received) << endl;
		}
	}
	void test_case_0() {
		int Arr0[] = { 1, 2, 3 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 2;
		int Arr2[] = { 2, 1 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		verify_case(0, Arg2, getRange(Arg0, Arg1));
	}
	void test_case_1() {
		int Arr0[] = { 8, 5, 6, 7 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 22;
		int Arr2[] = { 0, 0 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		verify_case(1, Arg2, getRange(Arg0, Arg1));
	}
	void test_case_2() {
		int Arr0[] = { 676, 11, 223, 413, 823, 122, 547, 187, 28 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 1000;
		int Arr2[] = { 7, 2 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		verify_case(2, Arg2, getRange(Arg0, Arg1));
	}
	void test_case_3() {
		int
				Arr0[] = { 955, 96, 161, 259, 642, 242, 772, 369, 311, 785, 92,
						991, 620, 394, 128, 774, 973, 94, 681, 771, 916, 373,
						523, 100, 220, 993, 472, 798, 132, 361, 33, 362, 573,
						624, 722, 520, 451, 231, 37, 921, 408, 170, 303, 559,
						866, 412, 339, 757, 822, 192 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 3619;
		int Arr2[] = { 46, 30 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		verify_case(3, Arg2, getRange(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	FanFailure c;
	c.__test();
	return 0;
}
// END CUT HERE
