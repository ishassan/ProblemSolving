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

class PirateTreasure {
public:
double getDistance(vector <int> steps, vector <string> directions)
{
	int sz = steps.size();
	double x=0,y=0;
	double c = sqrt(2.0)/2;
	fo(i,sz){
		if(directions[i]=="NORTH")
			y += steps[i];
		else if(directions[i]=="SOUTH")
			y -= steps[i];
		else if(directions[i]=="EAST")
			x += steps[i];
		else if(directions[i]=="WEST")
			x -= steps[i];
		else if(directions[i]=="NORTHEAST")	// 1 step northeast = rt2 / 2 to x && root2/2 to y
			x += steps[i]*c, y+= steps[i]*c;
		else if(directions[i]=="SOUTHEAST")
			x +=steps[i]*c , y-=steps[i]*c;
		else if(directions[i]=="NORTHWEST")
			x -= steps[i]*c , y += steps[i]*c;
		else
			x -= steps[i]*c , y-= steps[i]*c;
	}

	return sqrt( x*x + y*y);



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
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTHWEST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,10,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EAST","WEST","EAST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {34,48,34}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTH","SOUTHWEST","EAST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.08326112068522587; verify_case(3, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,2,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTH","NORTH","NORTH","NORTHWEST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.744277676240694; verify_case(4, Arg2, getDistance(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
PirateTreasure c;
c.__test();
return 0;
}
// END CUT HERE
