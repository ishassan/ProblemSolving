#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int graph[125][125];
int cost[125][125];
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

int n;
int BFS(){
	queue<pair<int,int> > q;
	q.push(mp(0,0));
	cost[0][0] = graph[0][0];
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();

		if(p.first == n-1 && p.second==n-1)
			continue;
		fo(d,4){
			int ni = p.first+di[d];
			int nj = p.second+dj[d];

			if(ni<0 || nj<0 || ni>=n||nj>=n)
				continue;

			if(cost[ni][nj] <= cost[p.first][p.second]+graph[ni][nj])
				continue;

			cost[ni][nj] = cost[p.first][p.second]+graph[ni][nj];
			q.push(mp(ni,nj));
		}
	}

	return cost[n-1][n-1];
}
int main() {


	while (cin >> n) {

		fo(i,125)
				fill(cost[i],cost[i]+125,1<<27);

		fo(i,n)
			fo(j,n)
				cin >> graph[i][j];

		cout<<BFS()<<endl;
	}
	return 0;
}
