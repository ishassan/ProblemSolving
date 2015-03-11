//TC 448 -D2-1		Points = 233.75 of 250
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

class TheBlackJackDivTwo {
public:
int score(vector <string> cards)
{
	string cur;
	int res=0;
	fo(i,cards.size()){
		cur = cards[i];

		if(cur[0]>'1' && cur[0]<='9')
			res += (cur[0])-'0';

		else if(cur[0] =='T' || cur[0] =='Q' || cur[0] =='K' || cur[0] =='J')
			res += 10;

		else if(cur[0] =='A')
			res += 11;
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
	void test_case_0() { string Arr0[] = {"4S", "7D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(0, Arg1, score(Arg0)); }
	void test_case_1() { string Arr0[] = {"KS", "TS", "QC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(1, Arg1, score(Arg0)); }
	void test_case_2() { string Arr0[] = {"AS", "AD", "AH", "AC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(2, Arg1, score(Arg0)); }
	void test_case_3() { string Arr0[] = {"3S", "KC", "AS", "7C", "TC", "9C", "4H", "4S", "2S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(3, Arg1, score(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
TheBlackJackDivTwo c;
c.__test();
return 0;
}
// END CUT HERE
