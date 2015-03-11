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
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdi pair<double,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define mit map<int, string>::iterator
typedef long long ll;
using namespace std;

int len,cnt;
int memo[102][102][2];
int DP(int idx, int rem, bool lastBit){
	if(rem < 0)
		return 0;
	if(idx>=len)
		return !rem;
	int& m =memo[idx][rem][lastBit];
	if(m!=-1)
		return m;

	m=DP(idx+1,rem,0);
	m+=DP(idx+1,rem-lastBit,1);
	return m;
}
int main() {

	int tst;
	scanf("%d",&tst);
	while(tst--){
		int t;
		mem(memo,-1);
		scanf("%d%d%d",&t,&len,&cnt);
		printf("%d %d\n",t,DP(0,cnt,0));
	}

	return 0;
}
