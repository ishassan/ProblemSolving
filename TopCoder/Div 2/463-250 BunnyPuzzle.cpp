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

class BunnyPuzzle {
public:
	int theCount(vector<int> v) {
		sort(all(v));

		int sz = v.size(), res = 0;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++) {
				if (i == j)
					continue;
				int jump = 2 * v[j] - v[i];
				if (jump > v[i]) {
					int k = i + 1, count = 0;
					while (k < sz) {
						if (v[k] > jump)
							break;

						count++;
						if (v[k] == jump)
							count = 2;
						if (count == 2)
							break;
						k++;
					}
					if (count == 1)
						res++;
				}

				else if (jump < v[i]) {
					int k = i - 1, count = 0;
					while (k > -1) {
						if (v[k] < jump)
							break;

						count++;
						if (v[k] == jump)
							count = 2;
						if (count == 2)
							break;
						k--;
					}
					if (count == 1)
						res++;
				}
			}

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
		int Arr0[] = { 5, 8 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 2;
		verify_case(0, Arg1, theCount(Arg0));
	}
	void test_case_1() {
		int Arr0[] = { -1, 0, 1 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 2;
		verify_case(1, Arg1, theCount(Arg0));
	}
	void test_case_2() {
		int Arr0[] = { 0, 1, 3 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 3;
		verify_case(2, Arg1, theCount(Arg0));
	}
	void test_case_3() {
		int Arr0[] = { -677, -45, -2, 3, 8, 29, 384, 867 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 7;
		verify_case(3, Arg1, theCount(Arg0));
	}
	void test_case_4() {
		int Arr0[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 2;
		verify_case(4, Arg1, theCount(Arg0));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	BunnyPuzzle c;
	c.__test();
	return 0;
}
// END CUT HERE
