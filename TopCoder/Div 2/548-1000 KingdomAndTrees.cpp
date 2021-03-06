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

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
typedef long long ll;
using namespace std;


class KingdomAndTrees {
public:
    vi h;
    bool isvalid(ll mid){
        vi cp = h;
        cp[0] = max(1LL, cp[0]-mid);
        reps(i,1,sz(cp)){
            if(cp[i] > cp[i-1]) {
                int dec = min(cp[i]-cp[i-1]-1LL,mid);
                cp[i] -= dec;
            }
            else{
                int inc = (cp[i-1]+1) - cp[i];
                if(inc > mid) return 0;
                cp[i] = cp[i-1]+1;
            }
        }
        return 1;
    }

	int minLevel(vector <int> heights) {
        h = heights;
        ll st=0, en=50000000010LL;
        ll yes=0;
        while(st < en){
            ll mid = (st+en)/2;
            if(isvalid(mid))
                en = mid,yes=mid;
            else
                st = mid+1;
        }
        return yes;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	KingdomAndTrees *obj;
	int answer;
	obj = new KingdomAndTrees();
	clock_t startTime = clock();
	answer = obj->minLevel(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <int> p0;
	int p1;
	
    {
    // ----- test 4 -----
    int t0[] = {1000000000,999999999,999999998,999999997,999999996,999999995,999999994,999999993,999999992,999999991,999999990,999999989,999999988,999999987,999999986,999999985,999999984,999999983,999999982,999999981,999999980,999999979,999999978,999999977,999999976,999999975,999999974,999999973,999999972,999999971,999999970,999999969,999999968,999999967,999999966,999999965,999999964,999999963,999999962,999999961,999999960,999999959,999999958,999999957,999999956,999999955,999999954,999999953,999999952,999999951};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    all_right = KawigiEdit_RunTest(4, p0, false, p1) && all_right;
    // ------------------
    }

	{
	// ----- test 0 -----
	int t0[] = {9,5,11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {548,47,58,250,2012};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 251;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
