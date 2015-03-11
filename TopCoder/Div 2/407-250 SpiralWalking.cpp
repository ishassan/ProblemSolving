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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef stringstream sstr;

class SpiralWalking {
public:
	bool vis[60][60];
int totalPoints(vector <string> arr)
{
	memset(vis,0,sizeof vis);
	int x=0,y=0,res=0;
	int xsz = arr.size(), ysz=arr[0].size();
	int lim = xsz/2 + 1;
	int fx=0,fy=0;
	while(lim--){
		bool b=0;
		while(y< ysz && !vis[x][y]){
			res += arr[x][y]-'0';
			vis[x][y++]=1;
			b=1;
		}
		if(b){
		res -= arr[x][--y]-'0',b=0;
		fx=x,fy=y;
		x++;
		}

		while(x<xsz && !vis[x][y]){
			res += arr[x][y]-'0';
			vis[x++][y] =1;
			b=1;
		}
		if(b){
			res-= arr[--x][y]-'0', b=0;
			fx=x,fy=y;
			y--;
		}

		while(y>-1 && !vis[x][y]){
			res += arr[x][y]-'0';
			vis[x][y--]=1;
			b=1;
		}
		if(b){
			res -= arr[x][++y]-'0',b =0;
			fx=x,fy=y;
			x--;
		}

		while(x>0 && !vis[x][y]){
			res+= arr[x][y]-'0';
			vis[x--][y]=1;
			b=1;
		}
		if(b){
			res -= arr[++x][y]-'0', b=0;
			fx=x, fy=y;
			y++;
		}



	}

	res += arr[fx][fy]-'0';
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
	void test_case_0() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, totalPoints(Arg0)); }
	void test_case_1() { string Arr0[] = {"101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, totalPoints(Arg0)); }
	void test_case_2() { string Arr0[] = {"00",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, totalPoints(Arg0)); }
	void test_case_3() { string Arr0[] = {"86850",
 "76439",
 "15863",
 "24568",
 "45679",
 "71452",
 "05483"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 142; verify_case(3, Arg1, totalPoints(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
SpiralWalking c;
c.__test();
return 0;
}
// END CUT HERE
