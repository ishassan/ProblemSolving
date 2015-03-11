#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>


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

bool isprime(int n){
	if(n == 2)
		return 1;

	if(n<2 || n%2==0)
		return 0;

	for (int i = 3; i*i <= n; i+=2) {
		if(n%i==0)
			return 0;
	}

	return 1;
}

int memo[7995][5];
int DP(int sum, int k){
	if(sum==0)
		return 1;

	if(k==0)
		return 0;

	int& m = memo[sum][k];
	if(m != -1)
		return m;

	m = DP(sum, k-1);
	m += DP(sum-k, k);

	return m;
}
int main() {

	int n;
	scanf("%d",&n);
	if(n % 10)
		printf("1\n%d\n", n % 10);
	else
		printf("2\n");



	return 0;
}
