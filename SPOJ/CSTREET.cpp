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
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

const int SIZE=1002,OO=1<<27;
int n,adjmax[SIZE][SIZE];
int MST() {
	bool vis[SIZE]={0};
	int dist[SIZE];
	fill(dist,dist+n,OO), dist[0] = 0;
	int mstCost = 0, cur = 0;
	for (int k = 1; k < n; k++) {
		vis[cur] = 1;
		int val = OO, idx = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i])
				continue;

			if (adjmax[cur][i] < dist[i])
				dist[i] = adjmax[cur][i];

			if (dist[i] < val)
				val = dist[i], idx = i;
		}
		cur = idx, mstCost += val;
	}
	return mstCost;
}
int main() {

	int tst,price,m,a,b,c;
	scanf("%d",&tst);
	while(tst--){
		scanf("%d",&price);
		scanf("%d%d",&n,&m);
		rep(i,n)	fill(adjmax[i],adjmax[i]+n,1<<27);

		rep(i,m){
			scanf("%d%d%d",&a,&b,&c), --a,--b;
			adjmax[a][b] = adjmax[b][a]=c;
		}

		printf("%d\n",MST()*price);
	}

	return 0;
}
