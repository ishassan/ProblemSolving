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
//l6D6a56HtdHNu9VqMKFkVs5b74ktZ49qYkPC2siS8Gs5b74f
class TextCompressor {
public:
	string longestRepeat(string sourceText) {

		int pos = 0, len = 0;
		for (int i = 0; i < sourceText.size(); i++) {

			vi start;
			for (int j = i + 1; j < sourceText.size(); j++) {
				if (sourceText[i] == sourceText[j])
					start.push_back(j);
			}

			for(int j=0; j<start.size(); j++){
				int s= start[j];

				int l=0;
				for(int c=0; c+s < sourceText.size(); c++){
					if(i+c == s)
						break;
					if(sourceText[i+c]==sourceText[s+c])
						l++;
					else
						break;
				}

				if(l>len)
					len = l, pos = i;
			}
		}

		return sourceText.substr(pos,len);
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
		string Arg0 = "ABCDABCFG";
		string Arg1 = "ABC";
		verify_case(0, Arg1, longestRepeat(Arg0));
	}
	void test_case_1() {
		string Arg0 = "ABABA";
		string Arg1 = "AB";
		verify_case(1, Arg1, longestRepeat(Arg0));
	}
	void test_case_2() {
		string Arg0 = "This is a test.";
		string Arg1 = "is ";
		verify_case(2, Arg1, longestRepeat(Arg0));
	}
	void test_case_3() {
		string Arg0 = "Testing testing 1 2 3.";
		string Arg1 = "esting ";
		verify_case(3, Arg1, longestRepeat(Arg0));
	}
	void test_case_4() {
		string Arg0 = "The quick brown fox jumps over the lazy dog.";
		string Arg1 = "he ";
		verify_case(4, Arg1, longestRepeat(Arg0));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	TextCompressor c;
	c.__test();
	return 0;
}
// END CUT HERE
