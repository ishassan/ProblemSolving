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

class DocumentSearch {
public:
int nonIntersecting(vector <string> doc, string search)
{
	string str;
	for(int i=0; i<doc.size(); i++)
		str+= doc[i];

	int pos,start =0,res=0;
	while(1){
		pos = str.find(search,start);

		if(pos==-1)
			return res;

		res++;
		start = pos + search.size();
	}






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
	void test_case_0() { string Arr0[] = {"ababababa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ababa"; int Arg2 = 1; verify_case(0, Arg2, nonIntersecting(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ababababa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aba"; int Arg2 = 2; verify_case(1, Arg2, nonIntersecting(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"abcdefghijklmnop",
 "qrstuvwxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "pqrs"; int Arg2 = 1; verify_case(2, Arg2, nonIntersecting(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"aaa", "aa", "a", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa"; int Arg2 = 3; verify_case(3, Arg2, nonIntersecting(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
DocumentSearch c;
c.__test();
return 0;
}
// END CUT HERE
