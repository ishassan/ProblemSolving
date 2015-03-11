/*
 TASK: fence
 LANG: C++
 ID: fci_isl1
 */

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
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define foi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define SZ(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
struct edj
{
	int to;
	int revI;
	bool vis;
};
vector<edj>  adj[501];
vector<int>  adj1[501];

int e;
bool cmp(int x,int y)
{
	return adj[e][x].to<adj[e][y].to;
}

int deg[501];
vector<int> res;
void tour(int i)
{
	fo(z,SZ(adj1[i]))
	{
		int k=adj1[i][z];
		if(adj[i][k].vis)continue;
		int j=adj[i][k].to;
		int rk=adj[i][k].revI;
		adj[i][k].vis=1;
		adj[j][rk].vis=1;
		tour(j);
	}
	res.push_back(i);
}
int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		edj e1={y,SZ(adj[y]),0};
		edj e2={x,SZ(adj[x]),0};
		adj[x].push_back(e1);
		adj[y].push_back(e2);
		adj1[x].push_back(e2.revI);
		adj1[y].push_back(e1.revI);
		deg[x]++;
		deg[y]++;
	}
	int fnz=-1,FO=-1;
	fo(i,501)
	{
		e=i;
		sort(all(adj1[i]),cmp);
		if(deg[i] && fnz==-1)fnz=i;
		if((deg[i]&1) && FO==-1)FO=i;
	}
	tour(FO==-1?fnz:FO);
	reverse(all(res));
	fo(i,SZ(res))
		cout<<res[i]<<endl;

	return 0;
}
