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

class Mailbox {
public:
int impossible(string collection, vector <string> address)
{

	int pos[300]={0};
	int adr[300]={0};
	int res=0;
	fo(i,collection.size())
		pos[collection[i]]++;

	fo(i,address.size()){
		fo(j,300)
				adr[j] = pos[j];

		fo(j,address[i].size()){
			if(address[i][j]!=' ' && adr[address[i][j]]==0){
				res++;
				break;
			}
			adr[address[i][j]]--;
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAAAABBCCCCCDDDEEE123456789"; string Arr1[] = {"123C","123A","123 ADA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, impossible(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPRSTUVWXYZ1234567890"; string Arr1[] = {"2 FIRST ST"," 31 QUINCE ST", "606 BAKER"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, impossible(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABCDAAST"; string Arr1[] = {"111 A ST", "A BAD ST", "B BAD ST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, impossible(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
Mailbox c;
c.__test();
return 0;
}
// END CUT HERE
