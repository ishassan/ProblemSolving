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

class Desertification {
public:
	int desertArea(vector<string> island, int T) {

		vector<pair<int, int> > p;
		bool change = 1;

		fo(t,T) {
			if (!change)
				break;
			change = 0;
			vector<pair<int, int> > p;

			fo(i,island.size())
				fo(j,island[i].size())
					if (island[i][j] == 'D') {
						if (i + 1 < island.size() && island[i+1][j]=='F')
							p.push_back(make_pair(i + 1, j)), change = 1;

						if (i - 1 > -1  && island[i-1][j]=='F')
							p.push_back(make_pair(i - 1, j)), change = 1;

						if (j + 1 < island[i].size() && island[i][j+1]=='F')
							p.push_back(make_pair(i, j + 1)), change = 1;

						if (j - 1 > -1 && island[i][j-1]=='F')
							p.push_back(make_pair(i, j - 1)), change = 1;

					}

			fo(i,p.size())
				island[p[i].first][p[i].second] = 'D';

		}

		int res = 0;
		fo(i,island.size()) {
			fo(j,island[i].size()) {
				if (island[i][j] == 'D')
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
		string Arr0[] = { "FFF", "FDF", "FFF" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 1;
		int Arg2 = 5;
		verify_case(0, Arg2, desertArea(Arg0, Arg1));
	}
	void test_case_1() {
		string Arr0[] = { "FFF", "FDF", "FFF" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 2;
		int Arg2 = 9;
		verify_case(1, Arg2, desertArea(Arg0, Arg1));
	}
	void test_case_2() {
		string Arr0[] = { "FFFFF", "FFDFF", "FFFFD", "FFFFF", "FFFFF" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 2;
		int Arg2 = 17;
		verify_case(2, Arg2, desertArea(Arg0, Arg1));
	}
	void test_case_3() {
		string Arr0[] = { "FFFFFF", "FFFFFF", "FFFFFF", "FFFFFF" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 1000000000;
		int Arg2 = 0;
		verify_case(3, Arg2, desertArea(Arg0, Arg1));
	}
	void test_case_4() {
		string Arr0[] = { "FFFFFDFFFF", "FDFDFFFFFF", "FFFFFFFFFD",
				"FFFFFFFFFF", "DDFFFFFFFF", "FFFFFFFFFD", "FFFFFFFFFF",
				"FFFFFFFDFF", "FFFFFFFDFF", "FFFFDDFFFF" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 3;
		int Arg2 = 90;
		verify_case(4, Arg2, desertArea(Arg0, Arg1));
	}
	void test_case_5() {
		string Arr0[] = { "FFFFFDFFFF", "FDFDFFFFFF", "FFFFFFFFFD",
				"FFFFFFFFFF", "DDFFFFFFFF", "FFFFFFFFFD", "FFFFFFFFFF",
				"FFFFFFFDFF", "FFFFFFFDFF", "FFFFDDFFFF" };
		vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 98765432;
		int Arg2 = 100;
		verify_case(5, Arg2, desertArea(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	Desertification c;
	c.__test();
	return 0;
}
// END CUT HERE
