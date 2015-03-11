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

#define SZ(a) (int)a.size()
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define foi(it,s) for(typeof(s.begin()) it=s.begin(); it!=s.end(); it++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int arr[1002];

int main() {
	int n, d;
	cin >> n >> d;
	fo(i,n)
		cin >> arr[i];

	int cnt =0;
	fo(i,n)
		fo(j,n) {
			if (i == j)
				continue;
			if(abs(arr[i]-arr[j]) <= d)
				++cnt;
		}

	cout<<cnt;
	return 0;
}
