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
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

string s;
int memo[52][52][52];
int DP(int idx, int c1, int c2)
{
     if(idx == sz(s)) return c1==c2?0:-1<<27;
     int& m = memo[idx][c1][c2];
     if(m != -1) return m;
     m = DP(idx+1,c1,c2);
     if(s[idx] == '>' && c2 == 0)
          m = max(m, DP(idx+1,c1+1,c2)+1);
     if(s[idx] == '<') 
          m = max(m, DP(idx+1,c1,c2+1)+1);
     return m;

}
class MagicalStringDiv1 {
public:
     int getLongest(string S) {
          s = S;
          mem(memo,-1);
          return DP(0,0,0);
     }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1)
{
     cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
     cout << "]" << endl;
     MagicalStringDiv1 *obj;
     int answer;
     obj = new MagicalStringDiv1();
     clock_t startTime = clock();
     answer = obj->getLongest(p0);
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
int main()
{
     bool all_right;
     all_right = true;

     string p0;
     int p1;

     {
          // ----- test 0 -----
          p0 = "<><><<>";
          p1 = 4;
          all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
          // ------------------
     }

     {
          // ----- test 1 -----
          p0 = ">>><<<";
          p1 = 6;
          all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
          // ------------------
     }

     {
          // ----- test 2 -----
          p0 = "<<<>>>";
          p1 = 0;
          all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
          // ------------------
     }

     {
          // ----- test 3 -----
          p0 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>";
          p1 = 24;
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
