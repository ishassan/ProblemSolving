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
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
string arr[4][3]={ {"CIRCLE", "SQUIGGLE",  "DIAMOND"} , {"RED", "BLUE",  "GREEN"} , {"SOLID", "STRIPED", "EMPTY"} , { "ONE", "TWO", "THREE"}};
class Matching {
public:

	string last(string s1,string s2,int ind){
		for(int i=0; i<3; i++){
			if(arr[ind][i] == s1 || arr[ind][i] == s2)
				continue;
			return arr[ind][i];
		}
	}

vector <string> findMatch(vector <string> first, vector <string> second)
{
	vs res(first.size());
	for(int i=0; i<first.size(); i++){
		if(first[i]==second[i])
			res[i] = second[i];
		else
			res[i] = last(first[i] , second[i], i);
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
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"DIAMOND","BLUE","SOLID","ONE"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DIAMOND","GREEN","SOLID","TWO"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "DIAMOND",  "RED",  "SOLID",  "THREE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findMatch(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"CIRCLE","GREEN","EMPTY","TWO"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DIAMOND","BLUE","STRIPED","ONE"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "SQUIGGLE",  "RED",  "SOLID",  "THREE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findMatch(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"DIAMOND","RED","SOLID","ONE"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SQUIGGLE","BLUE","SOLID","TWO"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "CIRCLE",  "GREEN",  "SOLID",  "THREE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findMatch(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"SQUIGGLE","RED","STRIPED","ONE"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SQUIGGLE","RED","STRIPED","ONE"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "SQUIGGLE",  "RED",  "STRIPED",  "ONE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findMatch(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
Matching c;
c.__test();
return 0;
}
// END CUT HERE
