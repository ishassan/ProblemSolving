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
typedef long long ll;
using namespace std;

const int MAX = 1000;

vector<pii> factorization(int n) { // O(sqrt(n))
	vector<pii> res;
	int pow = 0;
	int d = 1;
	for (int i = 2; i * i <= n; i += d, d = 2) {
		pow = 0;
		while (!(n % i))
			pow++, n /= i;
		if (pow != 0)
			res.push_back(mp(i,pow));

	}
	if (n > 1)
		res.push_back(mp(n,1));
	return res;
}

int number_of_factors(vector<pii>& fact) {
	int cnt = 0;
	rep(i,sz(fact))
		cnt += fact[i].second;
	return cnt;
}
int main() {

	int m, n, k;
	while (scanf("%d", &m) && m) {
		scanf("%d%d", &n, &k);
		int n_factor[MAX]={0};
		vector<pii> fact = factorization(n);
		rep(i,sz(fact))
			n_factor[fact[i].first] = fact[i].second;
		int nsum = number_of_factors(fact);

		vector<pii> num[102], denom[102];
		int delta[102];
		int numerator, denomerator;
		rep(i,k) {
			scanf("%d%d", &numerator, &denomerator);
			num[i] = factorization(numerator);
			denom[i] = factorization(denomerator);
			delta[i] = number_of_factors(num[i]) - number_of_factors(denom[i]);
		}

		while (m) {
			if (nsum == n_factor[2]) {
				--m;
				printf("%d%c", nsum, (m) ? ' ' : '\n');
			}

			rep(i,k) {
				repi(it,denom[i]) {
					if (n_factor[it->first] < it->second)
						goto notvalid;
				}

				repi(it,num[i])
					n_factor[it->first] += it->second;

				repi(it,denom[i])
					n_factor[it->first] -= it->second;

				nsum += delta[i];
				break;
				notvalid:;
			}
		}

	}

	return 0;
}




