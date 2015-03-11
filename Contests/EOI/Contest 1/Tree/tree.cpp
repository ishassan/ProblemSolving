/*
ID: Manal Sadek
LANG: C++
TASK:
*/

#include <map>
#include <set>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <fstream>
using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,s,m) for(int i=s;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define PI = (2.0 * acos(0.0));
typedef stringstream ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define OO ((int)1e9)


int main()
{

    int f , t , tc = 1;
    set<int> s;
    cin>>f>>t;
      int e = 0;
      s.clear();
      while(f!=0 && t!=0)
      {
         s.insert(t);
         s.insert(f);
         e++;
         cin>>f>>t;
      }
      if(s.size() == 0 || e+1 == s.size()) printf("is a tree.\n");
      else printf("is not a tree.\n");

  //  system("pause");
    return 0;
}
