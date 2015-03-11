/*
 TASK: range
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

int arr[251][251];
int res[251];

int main() {
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);

	int n;
	scanf("%d", &n);
	foe(i,1,n)
		foe(j,1,n) {
			char c;
			scanf(" %c", &c);
			if(c=='0')
				continue;
			arr[i][j]=min(arr[i-1][j-1], min(arr[i-1][j] , arr[i][j-1])) + 1;
			foe(k,2,arr[i][j])
			res[k]++;
		}

	foe(i,2,n){
		if(res[i])
			cout<<i<<" "<<res[i]<<endl;
	}



	return 0;
}
