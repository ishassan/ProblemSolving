#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class MedalTable {
public:
	void sort(vector<pair<string, pair<int, pair<int, int> > > > &v){
		int sz = v.size();

		for(int i=0; i<sz; i++){
			for(int j= i+1; j<sz; j++){

				if(v[i].second.first < v[j].second.first)
					swap(v[i] , v[j]);

				else if(v[i].second.first == v[j].second.first){

					if(v[i].second.second.first < v[j].second.second.first)
						swap(v[i],v[j]);

					else if(v[i].second.second.first == v[j].second.second.first){
						if(v[i].second.second.second < v[j].second.second.second)
							swap(v[i],v[j]);

						else if(v[i].second.second.second == v[j].second.second.second){
							if(v[i].first > v[j].first)
								swap(v[i],v[j]);
						}
					}
				}
			}
		}
	}
vector <string> generate(vector <string> results)
{

	map<string,pair<int,pair<int,int> > > m;

	for(int i=0; i<results.size(); i++){
		stringstream ss(results[i]);
		string s;
		ss>>s , m[s].first++;
		ss>>s , m[s].second.first++;
		ss>>s , m[s].second.second++;
	}

	vector<pair<string,pair<int,pair<int,int> > > > v(m.begin(),m.end());

	sort(v);
	vs res;
	for(int i=0; i<v.size(); i++){
		stringstream ss;
		ss << v[i].first <<" "<< v[i].second.first<<" "<<v[i].second.second.first<<" "<<v[i].second.second.second;
		res.push_back(ss.str());
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
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
	void test_case_1() { string Arr0[] = {"USA AUT ROM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
	void test_case_2() { string Arr0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
MedalTable c;
c.__test();
return 0;
}
// END CUT HERE
