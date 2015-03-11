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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

int sol[35];

int main() {

	int tst;
	scanf("%d",&tst);
	foe(t,1,tst){
		memset(sol,0,sizeof sol);
		int n,term=0;
		scanf("%d",&n);
		while(n){
		int tmp = n,cnt=0,mul=1;
		while(tmp>1)
			tmp /=2, mul*=2, cnt++;
		sol[term++]=cnt;
		n -= mul;
		}

		printf("%d %d",t,term);
		fo(i,term)
			printf(" [%d,%d]",sol[i],0);
		printf("\n");
	}

	return 0;
}
