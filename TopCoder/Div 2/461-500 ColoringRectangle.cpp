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

double side(double hyp, double s) {
	return sqrt(hyp * hyp - s * s);
}

int solve(double w, double h, vi red, vi blue, bool type) {

	int r = red.size() - 1, b = blue.size() - 1;
	int res=0;
	while (w > 0.0) {
		if (type == 0) //red
		{
			if (r < 0 || red[r] < h)
				return -1;

			w -= 2 * side(red[r] / 2.0, h / 2.0);
			r--, res++, type = !type;
		} else {

			if (b < 0 || blue[b] < h)
				return -1;

			w -= 2 * side(blue[b] / 2.0, h / 2.0);
			b--, res++, type = !type;
		}
	}

	return res;

}
//461-500
class ColoringRectangle {
public:
	int chooseDisks(int width, int height, vector<int> red, vector<int> blue) {

		sort(all(red)), sort(all(blue));

		int res1 = solve((double) width, (double) height, red, blue, 0);
		int res2 = solve((double) width, (double) height, red, blue, 1);

		if(res1==-1)	return res2;
		if(res2==-1)	return res1;
		return min(res1,res2);
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
		int Arg0 = 11;
		int Arg1 = 3;
		int Arr2[] = { 5, 5 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		int Arr3[] = { 2, 5 };
		vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
		int Arg4 = 3;
		verify_case(0, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3));
	}
	void test_case_1() {
		int Arg0 = 30;
		int Arg1 = 5;
		int Arr2[] = { 4, 10, 7, 8, 10 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		int Arr3[] = { 5, 6, 11, 7, 5 };
		vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
		int Arg4 = 4;
		verify_case(1, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3));
	}
	void test_case_2() {
		int Arg0 = 16;
		int Arg1 = 4;
		int Arr2[] = { 6, 5, 7 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		int Arr3[] = { 5 };
		vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
		int Arg4 = -1;
		verify_case(2, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3));
	}
	void test_case_3() {
		int Arg0 = 4;
		int Arg1 = 4;
		int Arr2[] = { 5 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		int Arr3[] = { 6 };
		vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
		int Arg4 = 1;
		verify_case(3, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3));
	}
	void test_case_4() {
		int Arg0 = 6;
		int Arg1 = 2;
		int Arr2[] = { 6, 6 };
		vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		int Arr3[] = { 2 };
		vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
		int Arg4 = 3;
		verify_case(4, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	ColoringRectangle c;
	c.__test();
	return 0;
}
// END CUT HERE
