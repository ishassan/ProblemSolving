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

//dir: 0 up, 1 right, 2 down, 3 left
int DI[4]={-1,0,1,0};
int DJ[4]={0,1,0,-1};

int w,h,si=-1,sj=-1,di=-1,dj=-1;
char graph[102][102];
bool vis[102][102][4]={{{0}}};
int BFS(){
	deque<pair<pii,int> > q;
	q.push_back(mp(mp(si,sj),0));
	q.push_back(mp(mp(si,sj),1));
	q.push_back(mp(mp(si,sj),2));
	q.push_back(mp(mp(si,sj),3));
	int steps=0;
	while(q.size()){
		int size = q.size();
		while(size--){
			int ci = q.front().first.first;
			int cj = q.front().first.second;
			int dir = q.front().second;
			q.pop_front();

			if(ci==di && cj==dj)
				return steps;

			if(vis[ci][cj][dir])
				continue;
			vis[ci][cj][dir]=1;
			rep(d,4){
				int newi = ci + DI[d];
				int newj = cj + DJ[d];

				if(newi < 0 || newj < 0 || newi>=h || newj>=w )
					continue;
				if(vis[newi][newj][d] || graph[newi][newj]=='*' || ((d+2)%4)==dir)
					continue;

				if(d==dir)
					q.push_front(mp(mp(newi,newj),d)),size++;
				else
					q.push_back(mp(mp(newi,newj),d));
			}

		}
		steps++;
	}

	return -1e9;
}
int main() {

//	freopen("in.in","r",stdin);

	scanf("%d%d",&w,&h);
	rep(i,h){
		scanf("%s",graph[i]);
		rep(j,w)
			if(graph[i][j]=='C')
				if(si==-1)
					si=i,sj=j;
				else
					di=i,dj=j;
	}
	printf("%d\n",BFS());
	return 0;
}
