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

class MixtureDensity {
public:
double getDensity(vector <string> ingredients)
{
	int g=0,m=0;
	for(int i=0; i<ingredients.size(); i++){
		string s1,s2;
		int ind=0,sz = ingredients[i].size();
		while(isdigit(ingredients[i][ind]))
			s1+= ingredients[i][ind++];

		while(!isdigit(ingredients[i][ind]))
					ind++;

		while(ind<sz && isdigit(ingredients[i][ind]))
					s2+= ingredients[i][ind++];

		m += atoi(s1.c_str());
		g += atoi(s2.c_str());
	}

	return (double)g/m;






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
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"200 ml of oil, weighing 180 g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.9; verify_case(0, Arg1, getDensity(Arg0)); }
	void test_case_1() { string Arr0[] = {"100 ml of dichloromethane, weighing 130 g", "100 ml of sea water, weighing 103 g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.165; verify_case(1, Arg1, getDensity(Arg0)); }
	void test_case_2() { string Arr0[] = {"1000 ml of water, weighing 1000 g", "500 ml of orange juice concentrate, weighing 566 g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.044; verify_case(2, Arg1, getDensity(Arg0)); }
	void test_case_3() { string Arr0[] = {"1000 ml of something   l i g h t, weighing 1 g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0010; verify_case(3, Arg1, getDensity(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
MixtureDensity c;
c.__test();
return 0;
}
// END CUT HERE
