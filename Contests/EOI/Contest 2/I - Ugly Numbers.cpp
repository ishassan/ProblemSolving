#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

set<ll> res;
int main() {

	int n,nn;
	cin>>n;
	nn=n;
	res.insert(1);
	while(n-->1){
		ll t = *res.begin();
		res.erase(res.begin());
		res.insert(t*2),res.insert(t*3),res.insert(t*5);
	}

	printf("The %d'th ugly number is %lld.\n",nn,*res.begin());
	return 0;
}
