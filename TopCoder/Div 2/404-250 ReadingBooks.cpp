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

class ReadingBooks {
public:
int countBooks(vector <string> readParts)
{

	bool a=0,b=0,c=0;
	int count =0,res =0, pos =0;
	fo(i,readParts.size()){
		if(readParts[i]=="introduction")
			a=1;
		else if(readParts[i]=="story")
					b=1;
		else if(readParts[i]=="edification")
					c=1;
		count++;
		if(count==3){
			if(a && b &&c)
				res++, pos = i+1;
			else
				i = pos, pos++;

			a=b=c=count=0;
		}
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
	void test_case_0() { string Arr0[] = {"introduction", "story", "introduction", "edification"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countBooks(Arg0)); }
	void test_case_1() { string Arr0[] = {"introduction", "story", "edification", "introduction", "story", "edification"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, countBooks(Arg0)); }
	void test_case_2() { string Arr0[] = {"introduction", "story", "introduction", "edification", "story", "introduction"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countBooks(Arg0)); }
	void test_case_3() { string Arr0[] = {"introduction", "story", "introduction", "edification", "story",
 "story", "edification", "edification", "edification", "introduction",
 "introduction", "edification", "story", "introduction", "story",
 "edification", "edification", "story", "introduction", "edification",
 "story", "story", "edification", "introduction", "story"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, countBooks(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
ReadingBooks c;
c.__test();
return 0;
}
// END CUT HERE
