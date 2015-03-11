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
#define foo(i,m,n) for(int i=(m); i<(n); i++)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class ExerciseMachine {
public:
	int gcd(int a,int b){
		int m = min(a,b);

		while(a%m>0 || b%m>0)
			m--;

		return m;
	}
int getPercentages(string time)
{
	int h = (time[0]-'0')*10 +(time[1]-'0');
	int m = (time[3]-'0')*10 +(time[4]-'0');
	int s = (time[6]-'0')*10 +(time[7]-'0');

	s += (m*60) + (h*60*60);

	return gcd(s,100)-1;






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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00:30:00"; int Arg1 = 99; verify_case(0, Arg1, getPercentages(Arg0)); }
	void test_case_1() { string Arg0 = "00:28:00"; int Arg1 = 19; verify_case(1, Arg1, getPercentages(Arg0)); }
	void test_case_2() { string Arg0 = "23:59:59"; int Arg1 = 0; verify_case(2, Arg1, getPercentages(Arg0)); }
	void test_case_3() { string Arg0 = "00:14:10"; int Arg1 = 49; verify_case(3, Arg1, getPercentages(Arg0)); }
	void test_case_4() { string Arg0 = "00:19:16"; int Arg1 = 3; verify_case(4, Arg1, getPercentages(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
ExerciseMachine c;
c.__test();
return 0;
}
// END CUT HERE
