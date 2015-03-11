/*
 TASK: rockers
 LANG: C++
 ID: fci_isl1
 */

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
#include <valarray>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define foi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define SZ(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int n,m,t;

int memo[21][21][21];
int arr[21];

int calc(int remTape, int remTime, int idx){
	if(remTape == 0)
		return 0;

	if(remTime < 0)
		return -1e6;

	if(idx==n)
		return 0;

	int &m = memo[remTape][remTime][idx];
	if(m != -1)
		return m;

	m = calc(remTape, remTime - arr[idx], idx+1) + 1;
	m = max(m, calc(remTape, remTime, idx+1));
	m = max(m, calc(remTape-1, t, idx));

	return m;
}

int main() {
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);

	cin>>n>>t>>m;
	fo(i,n)
		cin>>arr[i];

	memset(memo, -1, sizeof memo);
	cout<<calc(m, t, 0)<<endl;
	return 0;
}
