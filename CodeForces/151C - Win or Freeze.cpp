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
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
typedef long long ll;
using namespace std;

const int MAX = 5000000;
long long primepow[MAX], prime[MAX], nprimes = 0;

void factorization(long long n) { // O(sqrt(n))
	nprimes = 0;
	long long pow = 0;
	int d = 1;
	for (long long i = 2; i * i <= n; i += d, d = 2) {
		pow = 0;
		while (!(n % i))
			pow++, n /= i;
		if (pow != 0)
			primepow[nprimes] = pow, prime[nprimes++] = i;
	}
	if (n > 1)
		primepow[nprimes] = 1, prime[nprimes++] = n;
}

long long divs[MAX]; //holds divisors
int sz = 0;
void generate_divisors(int ind = 0, long long mul = 1) {

	if (ind == nprimes) {
		divs[sz++] = mul;
		return;
	}
	long long x = 1;
	for (int i = 0; i <= primepow[ind]; i++) {
		generate_divisors(ind + 1, mul * x);
		x *= prime[ind];
	}
}

bool isprime(ll n) {
	if (n == 2)
		return 1;
	if (n < 2 || n % 2 == 0)
		return 0;
	for (ll i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

map<ll, bool> memo;
ll cpdiv[MAX];

bool DP(ll n) {
	sz = 0;
	factorization(n);
	generate_divisors();
	if (sz == 2)
		return 1;

	if (memo.count(n))
		return memo[n];

	rep(i,sz)
		cpdiv[i] = divs[i];

	int cpsz = sz;
	bool res = 1;
	rep(i,cpsz) {
		if (cpdiv[i] == n || cpdiv[i] == 1)
			continue;
		bool ret = DP(cpdiv[i]);
		if (ret == 0) {
			res = 0;
			break;
		}

	}
	memo[n] = !res;
	return !res;
}
int main() {

	ll n;
	cin >> n;

	if (isprime(n) || n==1) {
		cout <<1<<endl<< 0;
		return 0;
	}

	bool res = DP(n);
	if (res == 0)
		cout << 2;
	else {
		cout << 1 << endl;
		sz = 0;
		factorization(n);
		generate_divisors();
		rep(i,sz)
			cpdiv[i] = divs[i];

		int cpsz = sz;
		bool res = 1;
		rep(i,cpsz) {
			if (cpdiv[i] == n || cpdiv[i] == 1)
				continue;
			bool ret = DP(cpdiv[i]);
			if (ret == 0) {
				cout << cpdiv[i];
				return 0;
			}

		}
	}

	return 0;
}
