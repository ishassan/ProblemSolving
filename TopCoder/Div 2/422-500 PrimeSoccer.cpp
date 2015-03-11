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

class PrimeSoccer {
public:
	long long fact(int n) {
		long long res = n;
		while (n--)
			res *= n;
		return res;
	}
	double getProbability(int skillOfTeamA, int skillOfTeamB) {

		double skillA = skillOfTeamA/100.0;
		double skillB = skillOfTeamB/100.0;

		int primes[7] = { 2, 3, 5, 7, 11, 13, 17 };
		int nCr[7] = { 153, 816, 8568, 31824, 31824, 8568, 18 };

		//Probability to score exactly k intervals =
		//[S^K * (1 - S)^(18 - K)][18 C K]

		double pa = 0, pb = 0;
		fo(k,7) {
			//for Team A
			double x = pow(skillA, primes[k]) * pow((1 - skillA), 18 - primes[k]);
			pa += x * nCr[k];

			//for Team B
			double y = pow(skillB, primes[k]) * pow((1 - skillB),18 - primes[k]);
			pb += y * nCr[k];
		}

		return pa + pb - pa * pb;
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
	void verify_case(int Case, const double &Expected, const double &Received) {
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
		int Arg0 = 50;
		int Arg1 = 50;
		double Arg2 = 0.5265618908306351;
		verify_case(0, Arg2, getProbability(Arg0, Arg1));
	}
	void test_case_1() {
		int Arg0 = 100;
		int Arg1 = 100;
		double Arg2 = 0.0;
		verify_case(1, Arg2, getProbability(Arg0, Arg1));
	}
	void test_case_2() {
		int Arg0 = 12;
		int Arg1 = 89;
		double Arg2 = 0.6772047168840167;
		verify_case(2, Arg2, getProbability(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	PrimeSoccer c;
	c.__test();
	return 0;
}
// END CUT HERE
