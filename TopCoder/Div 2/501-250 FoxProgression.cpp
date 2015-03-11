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
 
#define sz(a) ((int)(a).size())
 
using namespace std;
 
class FoxProgression {
public:
  int theCount(vector <int> seq) {
    if(sz(seq)==1)
      return -1;
 
    if(sz(seq)==2){
 
      int cnt=(seq[0]!=seq[1]);
      if(seq[1]%seq[0]==0)
        ++cnt;
      return cnt;
    }
 
    int cnt=0;
    if(seq[1]%seq[0]==0){
      if(seq[2]%seq[1]==0){
        ++cnt;
      }
    }
 
    if(seq[1]-seq[0]==seq[2]-seq[1])
      ++cnt;
    return cnt;
  }
};
 
 
 
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
//With unused code cleaner (beta) by ahmed_aly

