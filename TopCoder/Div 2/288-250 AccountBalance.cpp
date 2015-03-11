//TC 288-D2-1	Points = 239.53 of 250	Time = 6m
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

class AccountBalance {
public:
int processTransactions(int startingBalance, vector <string> transactions)
{

	int res=startingBalance;
	string value;

	for(int i=0; i<transactions.size(); i++){

		value = transactions[i].substr(2,transactions[i].length() - 2);

		if(transactions[i][0]=='C')
			res += atoi(value.c_str());

		else
			res -= atoi(value.c_str());

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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; string Arr1[] = {"C 1000", "D 500", "D 350"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 250; verify_case(0, Arg2, processTransactions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; verify_case(1, Arg2, processTransactions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; string Arr1[] = {"D 50", "D 20", "D 40"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -10; verify_case(2, Arg2, processTransactions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 53874; string Arr1[] = {"D 1234", "C 987", "D 2345", "C 654", "D 6789", "D 34567"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10580; verify_case(3, Arg2, processTransactions(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
AccountBalance c;
c.__test();
return 0;
}
// END CUT HERE
