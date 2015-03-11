/*
TASK:
LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO=0;
const long double INF=1/ZERO,EPSILON=1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
vector<vector<char> > mat;
vector<vector<int> > goals;
struct state
{
	int i,j;
	int vis;
};
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool getDir(int i,int j,int k,int &ni,int &nj,int r,int c)
{
	ni=i+dir[k][0];
	nj=j+dir[k][1];
	return ni>=0 && ni<r && nj<c && nj>=0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in","rt",stdin);
	freopen("1.out","wt",stdout);
#endif
	int c,r;
	while(scanf("%d%d",&c,&r)&&(c||r))
	{
		mat.clear();
		goals.clear();
		mat.resize(r,vector<char>(c));
		goals.resize(r,vector<int>(c));
		int si,sj;
		int ng=0;
		rep(i,r)
			rep(j,c)
			{
				scanf(" %c",&mat[i][j]);
				if(mat[i][j]=='o')
					si=i,sj=j;
				else if(mat[i][j]=='*')
					goals[i][j]=ng++;
			}
		queue<state> q;
		state s={si,sj,0};
		q.push(s);
		int steps=0;
		vector<vector<vector<bool> > > vis(r,vector<vector<bool> >(c,vector<bool>(1<<ng)));
		vis[si][sj][0]=1;
		while(!q.empty())
		{
			int size=q.size();
			steps++;
			while(size--)
			{
				s=q.front();
				q.pop();
				rep(k,4)
				{
					state ns;
					if(getDir(s.i,s.j,k,ns.i,ns.j,r,c) && mat[ns.i][ns.j]!='x')
					{
						ns.vis=s.vis;
						if(mat[ns.i][ns.j]=='*')
							ns.vis|=1<<goals[ns.i][ns.j];
						if(ns.vis==(1<<ng)-1)
						{
							goto foundsol;
						}
						if(vis[ns.i][ns.j][ns.vis])
							continue;
						vis[ns.i][ns.j][ns.vis]=1;
						q.push(ns);
					}
				}
			}
		}
		printf("%d\n",-1);
		continue;
		foundsol:
		printf("%d\n",steps);
	}
	return 0;
}
