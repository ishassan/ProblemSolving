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

int n, m;
int male[2002];
vector<vi> adjlst;

bool BFS(int idx) {
	queue<pii> q;
	q.push(mp(idx,1));	//1:male,-1:female
	male[1]=1;
	while(q.size()){
		idx = q.front().first;
		int gen = q.front().second;
		q.pop();

		rep(i,sz(adjlst[idx])){
			int child = adjlst[idx][i];
			if(male[child]==gen)
				return 0;
			else if(male[child]==0){
				male[child] = -gen;
				q.push(mp(child,-gen));
			}
		}
	}
	return 1;
}
int main() {
	int tst, a, b,t=1;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d", &n, &m);
		mem(male,0);
		adjlst.clear();
		adjlst.resize(n + 3);

		rep(i,m) {
			scanf("%d%d", &a, &b);
			adjlst[a].push_back(b);
			adjlst[b].push_back(a);
		}

		printf("Scenario #%d:\n",t++);

		bool valid=1;
		repe(i,1,n){
			if(male[i]==0 && BFS(i)==0)
				valid=0;
		}
		printf(valid?"No suspicious bugs found!\n":"Suspicious bugs found!\n");
	}

	return 0;
}
