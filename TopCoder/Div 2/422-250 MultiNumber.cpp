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

class MultiNumber {
public:
string check(int number)
{
	vi num;

	if(number<10)
		return "NO";

	while(number>0){
		num.push_back(number%10);
		number /=10;
	}

	fo(i,num.size()){
		int p1=1,p2=1;
		fo(j,i)
			p1 *= num[j];


		foo(j,i,num.size())
			p2 *= num[j];
		if(p1==p2)
			return "YES";
	}

	return "NO";




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
	void test_case_0() { int Arg0 = 1; string Arg1 = "NO"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { int Arg0 = 1221; string Arg1 = "YES"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { int Arg0 = 1236; string Arg1 = "YES"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { int Arg0 = 4729382; string Arg1 = "NO"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { int Arg0 = 42393338; string Arg1 = "YES"; verify_case(4, Arg1, check(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
MultiNumber c;
c.__test();
return 0;
}
// END CUT HERE
