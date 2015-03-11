//TC 174 -D2-1		Points = 231.06 of 250		Time:8m
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
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

class CrossWord {
public:
	int countWords(vector<string> board, int size) {
		string cur;
		int ret = 0;
		fo(i,board.size()) {
			cur = board[i];
			int slots = 0;
			fo(j,cur.size()) {

				if (cur[j] == 'X') {
					if (slots == size)
						ret++;

					slots = 0;
					continue;
				}

				slots++;
			}

			if (slots == size)
				ret++;

			slots = 0;
		}

		return ret;

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
		string Arr0[] = { "X....X", "X.XX.X", "...X..", "X.XX.X", "..X..." };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 3;
		int Arg2 = 2;
		verify_case(0, Arg2, countWords(Arg0, Arg1));
	}
	void test_case_1() {
		string Arr0[] = { "...X...", ".X...X.", "..X.X..", "X..X..X",
				"..X.X..", ".X...X.", "...X..." };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 3;
		int Arg2 = 6;
		verify_case(1, Arg2, countWords(Arg0, Arg1));
	}
	void test_case_2() {
		string Arr0[] = { ".....X....X....", ".....X....X....",
				"..........X....", "....X....X.....", "...X....X....XX",
				"XXX...X....X...", ".....X....X....", ".......X.......",
				"....X....X.....", "...X....X...XXX", "XX....X....X...",
				".....X....X....", "....X..........", "....X....X.....",
				"....X....X....." };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 5;
		int Arg2 = 8;
		verify_case(2, Arg2, countWords(Arg0, Arg1));
	}
	void test_case_3() {
		string Arr0[] = { "...", "...", "..." };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 50;
		int Arg2 = 0;
		verify_case(3, Arg2, countWords(Arg0, Arg1));
	}
	void test_case_4() {
		string Arr0[] = { "....", "....", "...." };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 3;
		int Arg2 = 0;
		verify_case(4, Arg2, countWords(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	CrossWord c;
	c.__test();
	return 0;
}
// END CUT HERE
