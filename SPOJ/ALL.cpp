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

int n1,n2,d;
int simulate(int cur, vi ndep, vector<vi>dep){
	queue<int> q[2];
	repe(i,1,n1+n2)
		if(ndep[i]==0)
			q[i>n1?1:0].push(i);

	int steps=1;
	while(q[0].size() || q[1].size()){
		while(q[cur].size()){
			int dvd = q[cur].front();
			q[cur].pop();
			repi(it,dep[dvd]){
				if(--ndep[*it]==0)
					q[(*it)>n1?1:0].push(*it);
			}
		}
		cur ^=1;
		++steps;
	}
	return steps;
}
int main() {

	while(scanf("%d%d%d",&n1,&n2,&d) && (n1 || n2 || d)){
		vi ndep(n1+n2+1);
		vector<vi> dep(n1+n2+1);
		int x,y;
		rep(i,d){
			scanf("%d%d",&x,&y);
			ndep[x]++;
			dep[y].push_back(x);
		}
		printf("%d\n",min(simulate(0,ndep,dep),simulate(1,ndep,dep)));
	}

	return 0;
}
