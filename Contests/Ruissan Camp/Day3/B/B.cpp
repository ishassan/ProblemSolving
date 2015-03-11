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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;


int main(){

	freopen("kthmin.in","r",stdin);
	freopen("kthmin.out","w",stdout);
	multiset<ll> s;
	multiset<ll>::iterator it;
	int tst;
	scanf("%d",&tst);
	foe(t,1,tst){
		s.clear();
		ll m,n,k;
		ll sum=0;
		scanf("%d%d%d",&m,&n,&k);
		foo(i,1,n){
			ll r = (i*m)%n;
			s.insert(r);
			if(s.size()<k)
				continue;
			else if(s.size()==k){
				it = s.end();--it;
				sum += *it;
			}
			else{
				it = s.end(); --it;
				s.erase(it);
				it = s.end(); --it;
				sum += *it;
			}
		}
		printf("Case #%d: %d\n",t,sum);
	}


	return 0;
}
