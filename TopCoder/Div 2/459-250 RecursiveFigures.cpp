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
const double pi =3.141592654;
class RecursiveFigures {
public:
double getArea(int sideLength, int K)
{

	double r,d;
	d = sideLength;
	r = d/2;
	double area = pi*r*r;
	double sum =0;
	K--;
	while(K--){
		d = r*sqrt(2);
		r = d/2;
		
		sum += d*d - (pi*r*r);
		
	}
	
	return (area - sum);




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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; double Arg2 = 78.53981633974483; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; double Arg2 = 67.80972450961724; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; double Arg2 = 62.444678594553444; verify_case(2, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
RecursiveFigures c;
c.__test();
return 0;
}
// END CUT HERE
