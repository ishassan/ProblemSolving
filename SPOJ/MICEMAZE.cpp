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
int n,e,T,m;

int graph[102][102];
int main() {


	int f,t,c,res=0;
	scanf("%d%d%d%d",&n,&e,&T,&m);
	--e;
	rep(i,n)
		rep(j,n)
			graph[i][j]=1<<29;

	graph[e][e]=0;
	rep(i,m){
		scanf("%d%d%d",&f,&t,&c);
		graph[f-1][t-1]=min(c,graph[f-1][t-1]);
	}

	rep(k,n)
		rep(i,n)
			if(graph[i][e] > graph[i][k] + graph[k][e])
				graph[i][e] = graph[i][k] + graph[k][e];

	rep(i,n)
		if(graph[i][e]<=T)	++res;
	printf("%d\n",res);
	return 0;
}
