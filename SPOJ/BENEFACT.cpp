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

const int SIZE=50004;
vector<vector<pii> > adjlst;
int n;
int dist[SIZE];
int DijkstraWithHeap(int src){
	fill(dist,dist+n,1<<27);
	dist[src]=0;
	priority_queue<pii,vector<pii>, greater<pii> > q;
	q.push(mp(0,src));
	while(q.size()){
		src = q.top().second;
		int cst = q.top().first;
		q.pop();

		if(cst != dist[src])
			continue;

		repi(it, adjlst[src]){
			int nxt = it->second,nxtc = it->first;
			if(dist[nxt] > dist[src] + nxtc){
				dist[nxt] = dist[src] + nxtc;
				q.push(mp(dist[nxt],nxt));
			}

		}
	}
	int mx=0,idx;
	rep(i,n)
		if(dist[i] > mx)
			mx = dist[i], idx=i;
	return idx;
}
int main() {

	int tst,a,b,c;
	scanf("%d",&tst);
	while(tst--){
		scanf("%d",&n);
		adjlst.clear();
		adjlst.resize(n);
		reps(i,1,n){
			scanf("%d%d%d",&a,&b,&c),--a,--b;
			adjlst[a].push_back(mp(c,b));
			adjlst[b].push_back(mp(c,a));
		}

		int mxidx = DijkstraWithHeap(0);
		mxidx = DijkstraWithHeap(mxidx);
		printf("%d\n",dist[mxidx]);

	}

	return 0;
}

