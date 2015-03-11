#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
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

#define rep(i,n) for(int  i=0;i<(n);++i)
long double ZERO=0;
const long double INF=1/ZERO,EPSILON=1e-12;
#define all(c) (c).begin(),(c).end() 
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))

struct disjointSet {
	vector<int> p, rank;
	void reserve(size_t size) {
		if (size>p.size()) {
			int o=p.size();
			rank.resize(size);
			p.resize(size);
			rep2(i,o,size-1)
				p[i]=i,rank[i]=0;
		}
	}
	void merge(int x, int y) {
		reserve(max(x+1,y+1));
		int px=find(x);
		int py=find(y);
		if(px==py)return;
		if (rank[px]>rank[py])
			p[py]=px;
		else
			p[px]=py;
		if (rank[px]==rank[py])
			rank[py]++;
	}
	int find(int x) {
		reserve(x+1);
		return x!=p[x] ? p[x]=find(p[x]) : p[x];
	}
	void clear()
	{
		p.clear();
		rank.clear();
	}
	void operator()(int x,int y){
		merge(x,y);
	}
	int operator[](int x)
	{
		return find(x);
	}
};
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dir8[8][2]={{0,1},{1,0},{0,-1},{-1,0},{0,2},{2,0},{0,-2},{-2,0}};

bool getDir(int i,int j,int k,int &ni,int &nj,int r,int c,int dir[][2])
{
	ni=i+dir[k][0];
	nj=j+dir[k][1];
	return ni>=0 && ni<r && nj<c && nj>=0;
}
void ff(vector<vector<int> > &v,int x,int y,int c,int dir[][2],int ks)
{
	stack<pair<int,int> > s;
	s.push(make_pair(x,y));
	while(!s.empty())
	{
		x=s.top().first;
		y=s.top().second;
		s.pop();
		if(v[y][x]!=-1)
			continue;
		v[y][x]=c;
		rep(k,ks)
		{
			int ny,nx;
			if(getDir(y,x,k,ny,nx,v.size(),v[0].size(),dir))
			{
				s.push(make_pair(nx,ny));
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","rt",stdin);
	freopen("1.out","wt",stdout);
#endif
	int n;
	while(cin>>n && n)
	{
		vector<pair<int,int> > s,e;
		map<int,int> xs,ys;
		rep(i,n)
		{
			pair<int,int> p;
			cin>>p.first>>p.second;
			xs[p.first];
			ys[p.second];
			s.push_back(p);
			cin>>p.first>>p.second;
			xs[p.first];
			ys[p.second];
			e.push_back(p);
		}
		int cx=1;
		foreach(x,xs)
		{
			x->second=cx;
			cx+=2;
		}
		int cy=1;
		foreach(y,ys)
		{
			y->second=cy;
			cy+=2;
		}
		vector<vector<int> > v(cy,vector<int>(cx,-1));
		rep(i,n)
		{
			int sx=min(xs[s[i].first],xs[e[i].first]);
			int ex=max(xs[s[i].first],xs[e[i].first]);
			int sy=min(ys[s[i].second],ys[e[i].second]);
			int ey=max(ys[s[i].second],ys[e[i].second]);
			rep2(x,sx,ex)
				rep2(y,sy,ey)
					v[y][x]=0;
		}
		ff(v,0,0,0,dir,4);
		int c=0;
		rep(y,v.size())
			rep(x,v[y].size())
				if(v[y][x]==-1)
					ff(v,x,y,++c,dir8,8);
		cout<<c<<endl;
	}
	return 0;
}

