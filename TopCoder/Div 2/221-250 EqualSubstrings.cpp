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

class EqualSubstrings {
public:
vector <string> getSubstrings(string str)
{

	int res =-1;
		int a=0,b=0;
		fo(i,str.size()){
			a=b=0;
			for(int j=0; j<=i; j++){
				if(str[j]=='a')
					a++;
			}
			foo(j,i+1,str.size()){
				if(str[j]=='b')
					b++;
			}
			if(a==b)
				res =i;
		}

		vs ret(2);

		ret[0] = str.substr(0,res+1);
		ret[1] = str.substr(res+1,str.size()-res+1);

		return ret;





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
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aaabbb"; string Arr1[] = { "aaa",  "bbb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSubstrings(Arg0)); }
	void test_case_1() { string Arg0 = "bbbaaa"; string Arr1[] = { "bbb",  "aaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSubstrings(Arg0)); }
	void test_case_2() { string Arg0 = "bbbbbb"; string Arr1[] = { "bbbbbb",  "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSubstrings(Arg0)); }
	void test_case_3() { string Arg0 = "aaaaaa"; string Arr1[] = { "",  "aaaaaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSubstrings(Arg0)); }
	void test_case_4() { string Arg0 = "abjlkbjalkbjaljsbljbalb"; string Arr1[] = { "abjlkbjalkbjaljs",  "bljbalb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSubstrings(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
EqualSubstrings c;
c.__test();
return 0;
}
// END CUT HERE
