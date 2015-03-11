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

int memo[2501][2501];
class NameInput {
public:
	string s1, s2;
	int sz1, sz2;
	int DP(int ind1, int ind2) {
		int &m = memo[ind1][ind2];
		if (ind2 == sz2)
			return 0;

		if (s1[ind1] == s2[ind2])
			return m = DP(ind1, ind2 + 1);

		if (m != -1)
			return m;

		int right = 0, i = ind1;

		while (1) {
			i = (i + 1) % sz1;
			right++;
			if (s1[i] == s2[ind2]) {
				right = DP(i, ind2 + 1) + right;
				break;
			}
		}

		int left = 0;
		i = ind1;
		while (1) {
			i = (i - 1 + sz1) % sz1;
			left++;
			if (s1[i] == s2[ind2]) {
				left = DP(i, ind2 + 1) + left;
				break;
			}
		}

		return m = min(right, left);
	}
	int countUpDownKeyPresses(vector<string> predictionSequence,
			vector<string> name) {
		s1.clear(), s2.clear();

		fo(i,predictionSequence.size())
			s1 += predictionSequence[i];
		fo(i,name.size())
			s2 += name[i];

		sz1 = s1.size();
		sz2 = s2.size();
		fo(i,sz2) {
			bool found = 0;
			fo(j,sz1)
				if (s2[i] == s1[j]) {
					found = 1;
					break;
				}
			if (!found)
				return -1;
		}
		memset(memo, -1, sizeof memo);

		return DP(0, 0);

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
		if ((Case == -1) || (Case == 5))
			test_case_5();
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
		string Arr0[] = { "Jjhon" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "John" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 5;
		verify_case(0, Arg2, countUpDownKeyPresses(Arg0, Arg1));
	}
	void test_case_1() {
		string Arr0[] = { "abcdefghijklmnopqrstuvwxyz",
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "Joh", "nAndFr", "iends" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 186;
		verify_case(1, Arg2, countUpDownKeyPresses(Arg0, Arg1));
	}
	void test_case_2() {
		string Arr0[] = { "aaaabbbab", "baabbabaabba" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "bbaaababba", "baababababbb" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 16;
		verify_case(2, Arg2, countUpDownKeyPresses(Arg0, Arg1));
	}
	void test_case_3() {
		string Arr0[] = { "john" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "John" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = -1;
		verify_case(3, Arg2, countUpDownKeyPresses(Arg0, Arg1));
	}
	void test_case_4() {
		string Arr0[] = { "4" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "4444444444444" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 0;
		verify_case(4, Arg2, countUpDownKeyPresses(Arg0, Arg1));
	}
	void test_case_5() {
		string Arr0[] = { "abcABC123", "cbaCBA321" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "aB32C2AaB3c", "c32bA" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 38;
		verify_case(5, Arg2, countUpDownKeyPresses(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	NameInput c;
	c.__test();
	return 0;
}
// END CUT HERE
