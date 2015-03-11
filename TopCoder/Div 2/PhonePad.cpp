//Look at Sarkin's

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
#include <queue>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)
#define all(arr) arr.begin(),arr.end()

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;

class PhonePad {
public:
	int BFS(int src,int dist,bool vis[10][10],vector<vi>& graph){
		queue<int> q;
		q.push(src);
		int level =0;

		while(!q.empty()){
			int size = q.size();
			while(size--){
				src = q.front();
				q.pop();

				if(src==dist)
					return level;

				fo(i,graph[src].size()){
					if(vis[src][graph[src][i]])
						continue;
					vis[src][graph[src][i]]=1;
					vis[graph[src][i]][src]=1;
					q.push(graph[src][i]);
				}

			}
			level++;
		}
	}
int fingerMovement(string phoneNumber)
{

	vector<vi> graph(10);
	graph[0].push_back(8);
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(5);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[3].push_back(6);
	graph[4].push_back(1);
	graph[4].push_back(5);
	graph[4].push_back(7);
	graph[5].push_back(2);
	graph[5].push_back(4);
	graph[5].push_back(6);
	graph[5].push_back(8);
	graph[6].push_back(3);
	graph[6].push_back(5);
	graph[6].push_back(9);
	graph[7].push_back(4);
	graph[7].push_back(8);
	graph[8].push_back(5);
	graph[8].push_back(7);
	graph[8].push_back(9);
	graph[8].push_back(0);
	graph[9].push_back(6);
	graph[9].push_back(8);

	bool vis[10][10];


	phoneNumber = "5" + phoneNumber;
	int res =0;
	foo(i,1,phoneNumber.size()){
		memset(vis,0,sizeof vis);
		res += BFS(phoneNumber[i-1]-'0', phoneNumber[i]-'0',vis,graph);
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "911"; int Arg1 = 6; verify_case(0, Arg1, fingerMovement(Arg0)); }
	void test_case_1() { string Arg0 = "5555555"; int Arg1 = 0; verify_case(1, Arg1, fingerMovement(Arg0)); }
	void test_case_2() { string Arg0 = "8606335540"; int Arg1 = 16; verify_case(2, Arg1, fingerMovement(Arg0)); }
	void test_case_3() { string Arg0 = "8606574276"; int Arg1 = 21; verify_case(3, Arg1, fingerMovement(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
PhonePad c;
c.__test();
return 0;
}
// END CUT HERE
