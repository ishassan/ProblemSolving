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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

class MovingAverages {
public:
	vector<int> calculate(vector<string> times, int n) {
		int sum = 0;
		vi v;
		for (int i = 0; i <= times.size() - n; i++) {
			int nn = i + n;
			for (int j = i; j < nn; j++) {

				int h,m,s;

				sscanf(times[j].c_str(),"%d:%d:%d", &h,&m,&s);

				sum += h*3600 + m*60 + s;
			}

			v.push_back(sum/n);
			sum =0;

		}

		return v;

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
		string Arr0[] = { "01:19:10", "01:17:40", "01:19:44", "01:17:23",
				"01:17:07" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 3;
		int Arr2[] = { 4731, 4695, 4684 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		verify_case(0, Arg2, calculate(Arg0, Arg1));
	}
	void test_case_1() {
		string Arr0[] = { "01:19:10", "01:17:40", "01:19:44", "01:17:23",
				"01:17:07" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 1;
		int Arr2[] = { 4750, 4660, 4784, 4643, 4627 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		verify_case(1, Arg2, calculate(Arg0, Arg1));
	}
	void test_case_2() {
		string Arr0[] = { "01:19:10", "01:17:40", "01:19:44", "01:17:23",
				"01:17:07" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 5;
		int Arr2[] = { 4692 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		verify_case(2, Arg2, calculate(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	MovingAverages c;
	c.__test();
	return 0;
}
// END CUT HERE
