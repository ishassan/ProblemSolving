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
vi arrO, arrB;
vector<pair<char, int> > arr;

inline int sign(int val) {
	if(val >=0)
		return 1;
	return -1;
}

int main() {

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	int n, tst;
	scanf("%d", &tst);
	repe(t,1,tst) {
		scanf("%d", &n);
		arrO = arrB = vi();
		arr = vector<pair<char, int> > (n);

		rep(i,n) {
			scanf(" %c %d", &arr[i].first, &arr[i].second);
			if (arr[i].first == 'O')
				arrO.push_back(arr[i].second);
			else
				arrB.push_back(arr[i].second);
		}

		int o = 1, b = 1, oi = 0, bi = 0;
		int res = 0;
		rep(i,n){
			int dfb = abs(b - arrB[bi]);
			int dfo = abs(o - arrO[oi]);

			if(arr[i].first=='B' && arr[i].second == arrB[bi]){
				res += dfb;
				b = arrB[bi++];
				if(dfo > dfb)
					o += dfb * sign(arrO[oi] - o);
				else
					o = arrO[oi];

				++res;
				if(o != arrO[oi])
					o += sign(arrO[oi] - o);
			}

			else if(arr[i].first=='O' && arr[i].second == arrO[oi]){
				res += dfo;
				o = arrO[oi++];
				if(dfb > dfo)
					b += dfo * sign(arrB[bi] - b);
				else
					b = arrB[bi];

				++res;
				if(b != arrB[bi])
					b += sign(arrB[bi] - b);
			}

		}

		printf("Case #%d: %d\n",t,res);
	}
	return 0;
}
