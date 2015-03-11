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

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;

class MinDifference {
public:
int closestElements(int A0, int X, int Y, int M, int n)
{

	vi a(n);
	a[0]=A0;
	foo(i,1,n)
		a[i] = (a[i-1]*X + Y) % M;

	sort(a.begin(),a.end());

	fo(i,n-1){
		a[i] = a[i+1] - a[i];
	}
	a[n-1] = 10000000;
	sort(a.begin(), a.end());

	return a[0];

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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 1; int Arg3 = 101; int Arg4 = 5; int Arg5 = 6; verify_case(0, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 9; int Arg2 = 8; int Arg3 = 32; int Arg4 = 8; int Arg5 = 0; verify_case(1, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 67; int Arg1 = 13; int Arg2 = 17; int Arg3 = 4003; int Arg4 = 23; int Arg5 = 14; verify_case(2, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1221; int Arg2 = 3553; int Arg3 = 9889; int Arg4 = 11; int Arg5 = 275; verify_case(3, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10000; int Arg5 = 0; verify_case(4, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 1567; int Arg1 = 5003; int Arg2 = 9661; int Arg3 = 8929; int Arg4 = 43; int Arg5 = 14; verify_case(5, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
MinDifference c;
c.__test();
return 0;
}
// END CUT HERE
