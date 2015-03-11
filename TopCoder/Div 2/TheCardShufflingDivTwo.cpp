//TC  448-D2-2		Points =422.77 of 250(WA)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

class TheCardShufflingDivTwo {
public:
	int shuffle(int n, int m) {

		vi res;
		stack<int> l, r;

		for (int i = n; i > 0; i--)
			res.push_back(i);

		fo(i,m){
		while(res.size()>0) {
				l.push(res.back());
				res.pop_back();

			if (res.size() > 0) {
				r.push(res.back());
				res.pop_back();
			}
		}

		res.erase(res.begin(),res.end());

		while(! l.empty()){
			res.push_back(l.top());
			l.pop();
		}

		while(! r.empty()){
					res.push_back(r.top());
					r.pop();
				}


		}

		return res.back();

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
void run_test(int Case) {if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();}
private:
template <typename T> string print_array(const vector<T> &V) {ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str();}
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
	int Arg0 = 5;
	int Arg1 = 1;
	int Arg2 = 2;
	verify_case(0, Arg2, shuffle(Arg0, Arg1));
}
void test_case_1() {
	int Arg0 = 5;
	int Arg1 = 2;
	int Arg2 = 4;
	verify_case(1, Arg2, shuffle(Arg0, Arg1));
}
void test_case_2() {
	int Arg0 = 2;
	int Arg1 = 10;
	int Arg2 = 1;
	verify_case(2, Arg2, shuffle(Arg0, Arg1));
}
void test_case_3() {
	int Arg0 = 17;
	int Arg1 = 9;
	int Arg2 = 2;
	verify_case(3, Arg2, shuffle(Arg0, Arg1));
}

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheCardShufflingDivTwo c;
c.__test();
return 0;
}
// END CUT HERE
