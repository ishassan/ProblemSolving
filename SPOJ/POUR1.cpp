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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define mit map<char,vi>::iterator
typedef long long ll;
using namespace std;

int solve(int from, int to, int goal){
	int steps=0;
	int f=0,t=0;
	while(f!=goal && t!=goal){
		if(t==to)
			t=0;
		else if(f==0)
			f=from;
		else{
			int am = min(f, to-t);
			t+=am,f-=am;
		}
		++steps;
	}
	return steps;
}
int main() {

	int tst, a, b, c;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d%d", &a, &b, &c);
		if (c % __gcd(a, b) || (c > a && c > b)) {
			printf("-1\n");
			continue;
		}

		printf("%d\n",min(solve(a,b,c) , solve(b,a,c)));
	}
	return 0;
}
