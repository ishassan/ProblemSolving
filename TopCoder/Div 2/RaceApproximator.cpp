//TC 184 -D2-1		Points =204.09 of 250
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

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class RaceApproximator {
public:
string timeToBeat(int d1, int t1, int d2, int t2, int raceDistance)
{

// T1*e^(ln(T2/T1)*ln(D1/D)/ln(D1/D2))
//237 s

	int t = t1 * exp(log((double)t2/t1) * log((double)d1/raceDistance) / log((double)d1/d2));

	int mod = t % (3600);
	t /= 3600;
	int hours = t;

	t=mod;
	mod = t% 60;
	t /= 60;
	int min = t;

	string h,m,s;
	stringstream ss;
	ss<<hours;
	ss>>h;
	ss.clear();
	ss<<min;
	ss>>m;
	ss.clear();
	ss<<mod;
	ss>>s;

	if(m.size()==1)
			m = "0" +m;

	if(s.size()==1)
			s = "0" + s;

	return h+":"+m+":"+s;

}



// BEGIN CUT HERE
void __test()
{
// END CUT HERE

// BEGIN CUT HERE
		static bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }
// END CUT HERE

// BEGIN CUT HERE
}
// END CUT HERE

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 800; int Arg1 = 118; int Arg2 = 5000; int Arg3 = 906; int Arg4 = 1500; string Arg5 = "0:03:57"; verify_case(0, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 400; int Arg1 = 65; int Arg2 = 1600; int Arg3 = 350; int Arg4 = 800; string Arg5 = "0:02:30"; verify_case(1, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1600; int Arg1 = 299; int Arg2 = 10000; int Arg3 = 2360; int Arg4 = 5000; string Arg5 = "0:18:00"; verify_case(2, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 17; int Arg2 = 10000; int Arg3 = 4500; int Arg4 = 9000; string Arg5 = "1:06:00"; verify_case(3, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 156; int Arg1 = 117; int Arg2 = 3863; int Arg3 = 2754; int Arg4 = 1755; string Arg5 = "0:21:06"; verify_case(4, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
RaceApproximator c;
c.__test();
return 0;
}
// END CUT HERE
