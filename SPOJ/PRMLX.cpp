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
#include <map>

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
using namespace __gnu_cxx;

const int SIZE = 31;

map<int, int> fact[SIZE], num[SIZE];
int freq[SIZE];

void factorize(int n, map<int, int>& res) {
	res.clear();
	for (int i = 2, d = 1; i * i <= n; i += d, d = 2) {
		while (n % i == 0)
			++res[i], n /= i;
	}
	if (n > 1)
		++res[n];
}
void mul(map<int, int>& num1, map<int, int>& num2) {
	repi(it, num2)
		num1[it->first] += it->second;
}
void div(map<int, int>& num1, map<int, int>& num2) {
	repi(it, num2)
		if (num1[it->first] > 0)
			num1[it->first] -= it->second;
}
ll power(int n, int p) {
	if (p == 0)
		return 1;
	ll res = power(n, p / 2);
	res *= res;
	if (p % 2)
		res *= n;
	return res;
}
ll val(map<int, int>& h) {
	ll res = 1;
	repi(it, h)
		res *= power(it->first, it->second);
	return res;
}
int main() {

	//calculate factorials
	//num[i] = factorize(i)
	//num[i] = map<base,power> for i
	// fact[i] = map<base, power> for factorial of i
	reps(i,2,SIZE) {
		factorize(i, num[i]);
		fact[i] = fact[i-1];
		mul(fact[i], num[i]);
	}
	char str[SIZE];
	while (gets(str) && strcmp(str,"#")) {
		int len = strlen(str);
		if (len == 0) {
			printf("%10d\n", 1);
			continue;
		}
		rep(i,len)
			++freq[str[i] - 'a'];
		map<int, int> perm = fact[len];
		rep(i,26)
			div(perm, fact[freq[i]]);

		// p now contains ( n! / repeated! )
		ll res = 0;
		rep(i,len) {
			int c = str[i] - 'a';	//c = rank of char i
			rep(j,c) {
				if (freq[j] == 0)
					continue;
				map<int, int> tmp = perm;
				mul(tmp, num[freq[j]]);
				div(tmp, num[len - i]);	// pp = (n! / repeated!)
				res += val(tmp);	// res += result of mathimatical operation ( (n-1)! / (repeated-1)!)
							// this operation is done for every char less that c
			}

			// res now equal number of permutations when char i is fixed
			mul(perm, num[freq[c]]);	// p now equals (n! / (repeated after removing one elm of c)! )
			div(perm, num[len - i]);	// decreasing length of sequence. p = ( n-1! / ... )
			--freq[c];			// 1 element of c is removed
		}
		printf("%10d\n", res + 1);
	}
	return 0;
}
