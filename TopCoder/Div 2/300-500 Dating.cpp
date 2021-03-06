#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;


class Dating {
public:
	int getmax(string str,int idx, bool small){
		int mx=-1;
		char c='z'+1;
		fo(i,str.size()){
			if(i==idx || (bool)islower(str[i]) != small)
				continue;
			if(c>str[i])
				c=str[i], mx=i;
		}
		return mx;
	}
	string dates(string circle, int k) {
		char c,cc;
		int idx=0,idx2;
		string res="";
		while(circle.size()>1){
			idx += k-1, idx%=circle.size();
			c = circle[idx];
			idx2 = getmax(circle,idx,!islower(c));
			if(idx2==-1)
				break;
			cc = circle[idx2];
			res+=c,res+=cc,res+=" ";
			circle.erase(circle.begin()+idx);
			bool less = (idx<idx2);
			circle.erase(circle.begin() + idx2-less);
			idx -= !less;
		}

		if(res=="")
			return res;
		res.erase(res.end()-1);

		return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	Dating *obj;
	string answer;
	obj = new Dating();
	clock_t startTime = clock();
	answer = obj->dates(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "abXCd";
	p1 = 2;
	p2 = "bC dX";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "abXCd";
	p1 = 8;
	p2 = "Xa dC";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "HGFhgfz";
	p1 = 1;
	p2 = "Hf Gg Fh";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
