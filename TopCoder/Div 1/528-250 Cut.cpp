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
 
#define sz(a) ((int)(a).size())
 
#define all(n) (n).begin(),(n).end()
 
using namespace std;
 
class Cut {
public:
 
  int getMaximum(vector <int> eelLengths, int maxCuts) {
 
    int res=0;
    vector<int> ten;
    rep(i,sz(eelLengths)){
      if(maxCuts>0&&eelLengths[i]%10==0)
        ten.push_back(eelLengths[i]),eelLengths[i]=0;
      if(eelLengths[i]==10)
        ++res, eelLengths[i]=0;
    }
    sort(all(ten));
    rep(i,sz(ten)){
      int cnt = ten[i]/10;
      int cut = cnt-1;
      if(cut <= maxCuts)
        res += cnt, maxCuts-=cut;
      else
        res += maxCuts, maxCuts=0;
    }
    if(maxCuts ==0) return res;
 
    rep(i,sz(eelLengths)){
      if(maxCuts ==0 ) break;
      if(eelLengths[i]<10) continue;
      int cnt = eelLengths[i]/10;
      int cut = cnt;
      if(cut <= maxCuts)
        res += cnt, maxCuts-= cut;
      else
        res+=maxCuts, maxCuts=0;
    }
    return res;
  }
 
};
