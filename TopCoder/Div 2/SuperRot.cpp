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

class SuperRot {
public:
string decoder(string message)
{

	for(int i=0; i<message.size(); i++){
		if(isalpha(message[i])){
			if(isupper(message[i])){
				if(message[i]<78)
					message[i]+=13;
				else
					message[i]-=13;
			}
			else{
				if(message[i]<110)
									message[i]+=13;
								else
									message[i]-=13;
			}
		}

		else if(isdigit(message[i])){
			if(message[i]<'5')
				message[i] +=5;
			else
				message[i]-=5;
		}
	}


	return message;


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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Uryyb 28"; string Arg1 = "Hello 73"; verify_case(0, Arg1, decoder(Arg0)); }
	void test_case_1() { string Arg0 = "GbcPbqre"; string Arg1 = "TopCoder"; verify_case(1, Arg1, decoder(Arg0)); }
	void test_case_2() { string Arg0 = ""; string Arg1 = ""; verify_case(2, Arg1, decoder(Arg0)); }
	void test_case_3() { string Arg0 = "5678901234"; string Arg1 = "0123456789"; verify_case(3, Arg1, decoder(Arg0)); }
	void test_case_4() { string Arg0 = "NnOoPpQqRr AaBbCcDdEe"; string Arg1 = "AaBbCcDdEe NnOoPpQqRr"; verify_case(4, Arg1, decoder(Arg0)); }
	void test_case_5() { string Arg0 = "Gvzr vf 54 71 CZ ba Whyl 4gu bs gur lrne 7558 NQ"; string Arg1 = "Time is 09 26 PM on July 9th of the year 2003 AD"; verify_case(5, Arg1, decoder(Arg0)); }
	void test_case_6() { string Arg0 = "Gur dhvpx oebja sbk whzcf bire n ynml qbt"; string Arg1 = "The quick brown fox jumps over a lazy dog"; verify_case(6, Arg1, decoder(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
SuperRot c;
c.__test();
return 0;
}
// END CUT HERE
