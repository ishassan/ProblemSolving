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
#include <list>
#include <climits>
#include <assert.h>
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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

pair<ll,ll> extendEculid(ll a, ll b){
	ll x0 = 1, y0 = 0, R0 = a;
	ll x1 = 0, y1 = 1, R1 = b;

	ll resR=0;
	while(R1){
		ll q = R0/R1;
		resR = R0 - q * R1;
		R0 = R1, R1 = resR;

		ll newX = x0 - q*x1;
		x0 = x1, x1 = newX;

		ll newY = y0 - q*y1;
		y0 = y1, y1 = newY;
	}

	return mp(x0,y0);
}
int main() {

	ll a,b,c;
	cin>>a>>b>>c;
	c = -c;

	ll gcd = __gcd(a,b);
	if(c% gcd){
		printf("-1\n");
		return 0;
	}


	pair<ll,ll> p = extendEculid(a,b);
	cout<<p.first*(c/gcd)<<" "<<p.second*(c/gcd);
	return 0;
}

