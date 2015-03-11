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

    string s = "";
    cin>>s;
      int x = 0;
      int y = 2;
      for(int i = s.size()-1 ; i>=0 ; i--)
      {
        x+= (s[i]-'0')*(y-1);
        y*=2;
      }
      cout<<x<<endl;
       
    return 0;
}
