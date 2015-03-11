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
#define mit map<char,vi>::iterator
typedef long long ll;
using namespace std;

const int MAX = 100001;
int N;
vector<vector<pair<int, int> > > adjlst;
int dijkstraHeap(int start, int goal) {
	vector<int> dist(adjlst.size(), 1e9);
	priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int,
			int> > > q;
	q.push(make_pair(0, start));
	dist[start] = 0;
	while (!q.empty()) {
		pair<int, int> x = q.top();
		q.pop();
		if (x.first != dist[x.second])
			continue;
		int i = x.second;
		int c = x.first;
		if (i == goal)
			return c;
		repi (y,adjlst[i]) {
			if (c + y->first < dist[y->second]) {
				dist[y->second] = c + y->first;
				q.push(make_pair(dist[y->second], y->second));
			}
		}
	}
	return 1e9;
}

int main() {

	int tst,m,start,end,frm,to,cst;
	scanf("%d",&tst);
	while(tst--){
		scanf("%d%d%d%d",&N,&m,&start,&end);
		adjlst.clear();
		adjlst.resize(N);
		rep(i,m){
			scanf("%d%d%d",&frm,&to,&cst);
			adjlst[frm-1].push_back(mp(cst,to-1));
			adjlst[to-1].push_back(mp(cst,frm-1));
		}
		int res = dijkstraHeap(start-1,end-1);
		if(res==1e9)
			printf("NONE\n");
		else
			printf("%d\n",res);
	}
	return 0;
}
