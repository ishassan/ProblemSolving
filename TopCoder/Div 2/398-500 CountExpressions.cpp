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

class CountExpressions {
public:
	int xx,yy,v;
	int res;
	void calc(int count, int sum, int nx, int ny){
		if(count==3){
			if(sum==v)
				res++;
			return;
		}

		if(nx){
			calc(count+1, sum+xx, nx-1, ny);
			calc(count+1, sum-xx, nx-1, ny);
			calc(count+1, sum*xx, nx-1, ny);
		}

		if(ny){
			calc(count+1, sum+yy, nx, ny-1);
			calc(count+1, sum-yy, nx, ny-1);
			calc(count+1, sum*yy, nx, ny-1);
		}
	}
int calcExpressions(int x, int y, int val)
{
	xx = x, yy=y, v = val;
	res =0;
	calc(0,xx,1,2);
	calc(0,yy,2,1);

	return res;






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
	void test_case_0() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 16; int Arg3 = 9; verify_case(0, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 7; int Arg3 = 5; verify_case(1, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 98010000; int Arg3 = 6; verify_case(2, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = -99; int Arg1 = 42; int Arg2 = -1764; int Arg3 = 2; verify_case(3, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = -100; int Arg2 = -100000000; int Arg3 = 0; verify_case(4, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 5; int Arg3 = 17; verify_case(5, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
CountExpressions c;
c.__test();
return 0;
}
// END CUT HERE
