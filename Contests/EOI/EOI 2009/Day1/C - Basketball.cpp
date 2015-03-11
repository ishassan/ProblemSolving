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
#include <cstdio>
#include <cmath>
#include <cstdlib>


#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
using namespace std;

int n, q;
int arr[5003];

int main() {
	cin >> n >> q;
	fo(i,n)
		cin >> arr[i];

	int mx = -1;
	fo(i,n) {
		int sum = 0;
		for (int j = i; j < i + q; j++)
			sum += arr[j % n];
		mx = max(mx, sum);
	}
	cout << mx << "\n";
	return 0;
}
