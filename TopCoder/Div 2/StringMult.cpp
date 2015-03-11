//TC 199 -D2-1		Points = 233.95of 250		Time: 7m
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

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class StringMult {
public:
string times(string sFactor, int iFactor)
{
	string res="",temp="";
	if(sFactor=="" || iFactor==0)
		return "";

	if(iFactor> 0){
		while(iFactor--){
			res += sFactor;
		}

		return res;
	}

	for(int i =sFactor.length()-1; i>-1; i--)
		temp += sFactor[i];

	while(iFactor++){
		res += temp;

	}

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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "wOw"; int Arg1 = 0; string Arg2 = ""; verify_case(0, Arg2, times(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AbC"; int Arg1 = -3; string Arg2 = "CbACbACbA"; verify_case(1, Arg2, times(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "Boo"; int Arg1 = 4; string Arg2 = "BooBooBooBoo"; verify_case(2, Arg2, times(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ""; int Arg1 = 50; string Arg2 = ""; verify_case(3, Arg2, times(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "Racecar"; int Arg1 = -5; string Arg2 = "racecaRracecaRracecaRracecaRracecaR"; verify_case(4, Arg2, times(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
StringMult c;
c.__test();
return 0;
}
// END CUT HERE
