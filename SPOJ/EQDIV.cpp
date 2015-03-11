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


int n;
int graph[102][102];
bool vis[102][102];
bool visID[1000];
int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
void BFS(int row, int col){
	queue<pii> q;
	q.push(mp(row,col));
	vis[row][col]=1;
	visID[graph[row][col]]=1;

	while(q.size()){
		row = q.front().first;
		col = q.front().second ;
		q.pop();

		rep(d,4){
			int newi = row + di[d];
			int newj = col + dj[d];

			if(newi < 0 || newi>=n || newj<0 || newj>=n || vis[newi][newj] || graph[newi][newj]!=graph[row][col])
				continue;

			vis[newi][newj]=1;
			q.push(mp(newi,newj));
		}
	}
}
int main() {

	string str;
	while(scanf("%d",&n) && n){
		getline(cin,str);
		mem(graph,0);
		mem(vis,0);
		mem(visID,0);
		reps(i,1,n){
			getline(cin,str);
			sstr ss(str);
			int x,y;
			while(ss>>x>>y){
				graph[x-1][y-1]=i;
			}
		}

		bool fail=0;
		rep(i,n)
			rep(j,n){
				if(vis[i][j])
					continue;
				else if(visID[graph[i][j]]){
					fail=1;
					goto end;
				}
				BFS(i,j);
		}
		end:;
		if(fail)
			printf("wrong\n");
		else
			printf("good\n");

	}

	return 0;

}

