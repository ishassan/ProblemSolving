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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

class WordCompositionGame {
public:
	string score(vector<string> listA, vector<string> listB,
			vector<string> listC) {
		int r1 = 0, r2 = 0, r3 = 0;
		map<string, bool> m1, m2, m3;

		fo(i,listA.size()) {
			m1[listA[i]] = 1;
		}

		fo(i,listB.size()) {
			m2[listB[i]] = 1;
		}

		fo(i,listC.size()) {
			m3[listC[i]] = 1;
		}

		fo(i,listA.size()){
			if(m2[listA[i]] && m3[listA[i]])
				r1++;
			else if(m2[listA[i]] || m3[listA[i]])
				r1+=2;
			else
				r1+=3;
		}

		fo(i,listB.size()){
					if(m1[listB[i]] && m3[listB[i]])
						r2++;
					else if(m1[listB[i]] || m3[listB[i]])
						r2+=2;
					else
						r2+=3;
				}
		fo(i,listC.size()){
					if(m1[listC[i]] && m2[listC[i]])
						r3++;
					else if(m1[listC[i]] || m2[listC[i]])
						r3+=2;
					else
						r3+=3;
				}

		stringstream ss;
		ss<<r1<<"/"<<r2<<"/"<<r3;
		return ss.str();

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
		string Arr0[] = { "cat", "dog", "pig", "mouse" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "cat", "pig" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		string Arr2[] = { "dog", "cat" };
		vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		string Arg3 = "8/3/3";
		verify_case(0, Arg3, score(Arg0, Arg1, Arg2));
	}
	void test_case_1() {
		string Arr0[] = { "mouse" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "cat", "pig" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		string Arr2[] = { "dog", "cat" };
		vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		string Arg3 = "3/5/5";
		verify_case(1, Arg3, score(Arg0, Arg1, Arg2));
	}
	void test_case_2() {
		string Arr0[] = { "dog", "mouse" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "dog", "pig" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		string Arr2[] = { "dog", "cat" };
		vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		string Arg3 = "4/4/4";
		verify_case(2, Arg3, score(Arg0, Arg1, Arg2));
	}
	void test_case_3() {
		string Arr0[] = { "bcdbb", "aaccd", "dacbc", "bcbda", "cdedc", "bbaaa",
				"aecae" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		string Arr1[] = { "bcdbb", "ddacb", "aaccd", "adcab", "edbee", "aecae",
				"bcbda" };
		vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		string Arr2[] = { "dcaab", "aadbe", "bbaaa", "ebeec", "eaecb", "bcbba",
				"aecae", "adcab", "bcbda" };
		vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		string Arg3 = "14/14/21";
		verify_case(3, Arg3, score(Arg0, Arg1, Arg2));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	WordCompositionGame c;
	c.__test();
	return 0;
}
// END CUT HERE
