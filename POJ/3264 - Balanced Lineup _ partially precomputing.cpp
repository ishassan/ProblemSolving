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

int arr[50010];

pii query[50010];

void sameBlock(int i, int j){
	int mn = 1<<27, mx = -1<<27;
	repe(k,i,j){
		mn = min(mn, arr[k]);
		mx = max(mx, arr[k]);
	}

	printf("%d\n",mx-mn);
}
int main() {


	int n, q;
	scanf("%d%d", &n, &q);

	int sq = ceil(sqrt(n));
	int blk = ceil((double)n / sq);
	int cnt = 0;
	rep(i,sq) {
		int mn = 1<<27, mx = -1<<27;
		rep(j,blk){
			if(cnt==n)
				break;
			scanf("%d", arr + cnt);
			mn = min(mn, arr[cnt]);
			mx = max(mx, arr[cnt]);
			++cnt;
		}
		query[i] = mp(mn,mx);
	}

	int a,b;
	rep(i,q){
		scanf("%d%d",&a,&b);
		--a, --b;
		int sblk = a/blk, eblk = b/blk;
		int mn = 1<<27, mx=-1<<27;

		if(sblk==eblk){
			sameBlock(a,b);
			continue;
		}
		int eloop = sblk*blk+blk;
		reps(j,a,eloop){
			mn = min(mn, arr[j]);
			mx = max(mx, arr[j]);
		}

		int sloop = eblk*blk;
		repe(j,sloop, b){
			mn = min(mn, arr[j]);
			mx = max(mx, arr[j]);
		}

		reps(j, sblk+1, eblk){
			mn = min(mn, query[j].first);
			mx = max(mx, query[j].second);
		}

		printf("%d\n",mx-mn);
	}


	return 0;
}
