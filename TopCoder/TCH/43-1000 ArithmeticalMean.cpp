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

class ArithmeticalMean {
public:
	long long howMany(vector<int> elements, int L, int H) {
		// Meet in The Middle Technique
		int sz1 = elements.size() / 2;	//first half
		int sz2 = elements.size() - sz1;//second half
		vector<vi> subs(sz1 + 2);	//subsets of first half

		ll res = 0,sum=0;
		int cnt = 0;	//number of chosen elements
		for (int i = 1; i < (1 << sz1); i++) {
			sum=0,cnt=0;
			for (int j = 0; j < sz1; j++)
				if ((1 << j) & i)
					sum += elements[j], ++cnt;

			if (L * cnt <= sum && sum <= H * cnt) //L<= s/cnt <= H
				++res;
			subs[cnt].push_back(sum);
		}

		fo(i,sz1)
			sort(be(subs[i]));

		for (int i = 1; i < (1 << sz2); i++) {
			sum = 0, cnt = 0;
			for (int j = 0; j < sz2; j++)
				if ((1 << j) & i)
					sum += elements[sz1 + j], cnt++;

			if (L * cnt <= sum && sum <= H * cnt)
				++res;

			for (int j = 1; j <= sz1; j++) {
				// see explaining below
				ll LB = L * (cnt + j) - sum;
				ll UB = H * (cnt + j) - sum;

				res += upper_bound(be(subs[j]),UB)  - lower_bound(be(subs[j]),LB) ;
			}
		}
		return res;
	}
};
/*
 * dlw2ty law enta 3ndk count1 , count2 , sum2 , H , L
 msh t2dr tgib 3dd el values bta3t sum1 eli t722

 L< (sum1+sum2 )/(count1+count2) < H
 -> L*(count1+count2)-sum2 < sum1 <  H*(count1+count2)-sum2

 f keda :
 LB = L*(count1+count2)-sum2
 UB = H*(count1+count2)-sum2

 tyb el moshkla b2a enk mknsh m3ak count1 kman bs enta t2dr t loop 3la
 kol el values bt3tha w tshof fel array bt3ha hal f values bt722 el
 kalam d wla l2 w law f 3ddhom kam
 */

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector<int> p0, int p1, int p2,
		bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	ArithmeticalMean *obj;
	long long answer;
	obj = new ArithmeticalMean();
	clock_t startTime = clock();
	answer = obj->howMany(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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

	vector<int> p0;
	int p1;
	int p2;
	long long p3;

	{
		// ----- test 0 -----
		int t0[] = { 10, 1, 3 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 2;
		p2 = 6;
		p3 = 4ll;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = { 0 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = -1;
		p2 = 0;
		p3 = 1ll;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = { 0 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 100;
		p2 = 100;
		p3 = 0ll;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 3;
		p2 = 7;
		p3 = 949ll;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
