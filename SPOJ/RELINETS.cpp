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

const int SIZE = 20;
struct DisjointSets {
	int parent[SIZE], rank[SIZE], componentsCnt;
	DisjointSets(int n) {
		memset(rank, 0, sizeof rank);
		for (int i = 0; i < n; i++)
			parent[i] = i;
		componentsCnt = n;
	}
	int find(int e) {
		return parent[e] == e ? e : parent[e] = find(parent[e]);
	}
	bool join(int e1, int e2) {
		int p1 = find(e1), p2 = find(e2);
		if (p1 == p2)
			return 0;
		if (rank[p1] == rank[p2])
			rank[p1]++;
		if (rank[p2] > rank[p1])
			swap(p1, p2);
		parent[p2] = p1;
		componentsCnt--; // new components get merged
		return 1;
	}
};

struct Edge {
	int from, to;
	int cost;
	Edge(int from,int to,int cost): from(from),to(to),cost(cost){}
	Edge(){}
	bool operator<(const Edge  & e)	const{
		return cost<e.cost;
	}
};

int n,e;
vector<Edge> edg;

int cost[(1<<20) + 3];
bool isrel[(1<<20) + 3];
int idxRel[(1<<20) + 3], size=0;

bool isGraphConnected(int mask){
	DisjointSets d(n);
	int cst =0;
	rep(i,e){
		if(mask & (1<<i) ){
			cst += edg[i].cost;
			d.join(edg[i].from, edg[i].to);
		}
	}

	cost[mask] = cst;
	return isrel[mask] = (d.componentsCnt==1);
}

bool isReliable(int mask){

	rep(i,e){
		int removeEdge = mask & (~(1<<i));
		if(!isrel[removeEdge])
			return false;
	}
	return true;
}

int main() {

	int s,d,c;
	int mn,tst=1;
	while(scanf("%d%d",&n,&e) && (n || e)){
		edg.clear();
		edg.resize(2*e);
		size =0, mn = 1<<30;

		rep(i,e){
			scanf("%d%d%d",&s,&d,&c);
			Edge link(s-1,d-1,c);
			Edge link2(d-1,s-1,c);

			edg[i] = link;
			edg[e + i] = link2;
		}

		rep(i,1<<e){
			if(isGraphConnected(i))
				idxRel[size++] = i;
		}

		rep(i,size){
			if(isReliable(idxRel[i]))
				mn = min(mn, cost[idxRel[i]]);
		}

		if(mn==(1<<30))
			printf("There is no reliable net possible for test case %d.\n",tst++);

		else
			printf("The minimal cost for test case %d is %d.\n",tst++,mn);
	}

	return 0;
}
