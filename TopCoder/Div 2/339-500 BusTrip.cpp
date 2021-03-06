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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
using namespace std;

class BusTrip {
public:
	vi split(string str) {
		stringstream ss(str);
		int n;
		vi v;
		while (ss >> n)
			v.push_back(n);
		return v;
	}
	int returnTime(int N, vector<string> buses) {
		vector<vector<pii> > table(buses.size(), vector<pii> (1010, mp(-1,-1)));
		fo(i,buses.size()) {
			vi bus = split(buses[i]);
			int min = 0, idx = 0, nidx = 0;
			while (min <= 1000) {
				table[i][min].first = bus[idx];
				nidx = (idx + 1) % bus.size();
				table[i][min].second = bus[nidx];
				min += abs(bus[nidx] - bus[idx]);
				idx = nidx;
			}
		}

		int min = 0, stop = 0;
		bool first = 0;
		while (min <= 1001) {
			if (!stop && first)
				break;

			int i = 0;
			for (; i < table.size(); i++) {
				if (table[i][min].first == stop)
					break;
			}

			if (i == table.size()) {
				min++;
				continue;
			}

			if (!stop && !first)
				first = 1;

			stop = table[i][min].second;
			min += abs(table[i][min].first - stop) + 1;
		}
		min--;
		return (min > 1000) ? -1 : min;

	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector<string> p1, bool hasAnswer,
		int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	BusTrip *obj;
	int answer;
	obj = new BusTrip();
	clock_t startTime = clock();
	answer = obj->returnTime(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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

	int p0;
	vector<string> p1;
	int p2;

	{
		// ----- test 0 -----
		p0 = 3;
		string t1[] = { "0 1 2" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 12;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 51;
		string t1[] = { "0 5 10 15 20 25 30 35 40 50" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 1000;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 3;
		string t1[] = { "0 1 2", "2 1 0" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = -1;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 5;
		string
				t1[] = { "0 1 2 3 4", "3 1 2 0", "4 1 2 3 0", "1 2 0 3 4",
						"4 0" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 12;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = 25;
		string t1[] = { "24 14 9 7 2",
				"21 4 18 24 7 1 2 11 8 9 14 16 5 17 13 23 19 15 22",
				"12 22 24 9 1 5 10 8 7 18 16 19 4 13 17",
				"14 5 17 9 23 7 16 22 10 4 6",
				"19 8 1 9 24 3 5 22 16 7 6 4 10 23 17 0 13 15",
				"2 16 10 13 14 1 11 20 0 24 22 23 19 4 18", "19 15 18 0",
				"15 9 22 5 20 8 23 14 24 18 21 6 13 19",
				"2 6 19 3 21 10 20 22 24 13 16 15 8 18 17 14 5",
				"19 10 1 7 5 11 21 8 14 0 17 23 12 2 3 16" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 157;
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		p0 = 100;
		string t1[] = { "0 10 30 45 60 46 39 31 20", "9 20 0 86" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = -1;
		all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		p0 = 4;
		string t1[] = { "0 1 2 3", "3 2 0 1" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 12;
		all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		p0 = 51;
		string t1[] = { "0 5 10 15 20 25 30 35 40 45 50" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = -1;
		all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
