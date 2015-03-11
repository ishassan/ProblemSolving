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
#include <climits>

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

int n,arr[1003];


int main() {

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	int tst;
	scanf("%d",&tst);
	repe(t,1,tst){
		int ts=0,tx=0;
		scanf("%d",&n);
		rep(i,n){
			scanf("%d",arr+i);
			ts += arr[i], tx ^= arr[i];
		}

		sort(arr,arr+n);
		int bstsum=-1,sum=0,xr=0;

		for (int i = n-1; i > 0; --i) {
			sum += arr[i], xr ^= arr[i];
			if(sum < ts && sum >= ts-sum && xr==(tx ^ xr))
				bstsum = max(sum, bstsum);

			if(xr < (tx ^ xr))
				break;
		}
		printf("Case #%d: ",t);
		if(bstsum == -1)
			printf("NO\n");
		else
			printf("%d\n",bstsum);
	}

	return 0;
}
