/*
 * 11294-Wedding.cpp
 *
 *  Created on: Apr 11, 2011
 *      Author: ahmed
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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
typedef long long ll;
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<pii> > adjL;
int oo = (int) 1e9;
#define var(x ) (2*(x))
#define Not(x ) (1^(x))
#define w(x ) (2*(x))
#define h(x ) (2*(x) + 1)
vector<vi > adj;
void addOr(int a, int b) {
	adj[Not(a)].pb(b);
	adj[Not(b)].pb(a);
}
int getVar(int x, char c) {
	x = (c == 'h' ? h(x) : w(x));
	return var(x);
}
const int MX = 120;
int ind[MX], cmpId[MX], low[MX];
int nxt, nmCmp;
stack<int > s;
void tarj(int idx) {
	ind[idx ] = low [idx] = nxt++;
	s.push(idx);
	for (int i = 0; i < (int)adj[idx].size(); ++i) {
		int j = adj[idx][i];
		if(ind[j] == -1) {
			tarj(j);
			low[idx] = min(low[idx], low[j]);
		}
		else if(cmpId[j] == -1)
			low[idx] = min(low[idx], low[j]);
	}
	if(ind[idx] == low[idx]) {
		int x;
		do {
			x = s.top();
			s.pop();
			cmpId[x] = nmCmp;
		}while(x!=idx);
		++nmCmp;
	}
}

void scc() {
	memset(ind, -1, sizeof ind);
	memset(cmpId, -1, sizeof cmpId);
	nmCmp = nxt = 0;
	for (int i = 0; i < (int)adj.size(); ++i) {
		if(ind[i] == -1)
			tarj(i);
	}

}

vector<vector<int > >cmpadj;
void buildCmpG() {

	cmpadj.clear();
	cmpadj.resize(nmCmp);

	for (int i = 0; i < adj.size(); ++i) {
		for (int k = 0; k < adj[i].size(); ++k) {
			int j = adj[i][k];
			if(cmpId[i] != cmpId[j])
				cmpadj[cmpId[i]].pb(cmpId[j]);
		}
	}

}
int indeg[MX];
vector<int >res;
void topSort() {

	for (int i = 0; i < cmpadj.size(); ++i)
		for (int j = 0; j < cmpadj[i].size(); ++j)
			indeg[cmpadj[i][j]]++;

	queue<int > q;
	for (int i = 0; i < nmCmp; ++i) {
		if(indeg[i] == 0)
			q.push(i);
	}
	res.clear();
	while(q.size()) {
		int idx = q.front();
		q.pop();
		res.pb(idx);
		for (int k = 0; k < cmpadj[idx].size(); ++k)
			if(!--indeg[cmpadj[idx][k]])
				q.push(cmpadj[idx][k]);
	}
}

int cmpInv[MX], cmpVal[MX];



int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.txt", "rt", stdin);
#endif

	int n, m;
	while(scanf("%d%d", &n, &m) && (n||m))
	{
		adj.clear();
		adj.resize(n*4);
		int p = 0;
		p = w(p);
		p = var(p);
		addOr(p, p);
		for (int i = 0; i < n; ++i) {
			int x = var(h(i)), y = var(w(i));
			addOr(x, y);
			addOr(Not(x), Not(y));
		}
		for (int i = 0; i < m; ++i) {
			int x1, x2;
			char c1, c2;
			scanf("%d%c %d%c", &x1, &c1, &x2, &c2);
			x1 = getVar(x1, c1);
			x2 = getVar(x2, c2);
			addOr(x1, x2);
		}
		scc();
		int bad = 0;
		for (int i = 0; i < 4*n; i+=2) {
			int x,y;
			if((x=cmpId[i]) == (y=cmpId[Not(i)]))
				bad = 1;
			cmpInv[x] = y;
			cmpInv[y] = x;

		}
		if(bad )
		{
			printf("bad luck\n");
			continue;
		}
		buildCmpG();
		topSort();
		memset(cmpVal, -1, sizeof cmpVal);
		for (int i = 0; i < res.size(); ++i) {
			int c = res[i];
			if(cmpVal[c] != -1)continue;
			cmpVal[c] = 0;
			cmpVal[cmpInv[c] ] = 1;
		}
		char *s = "";
		for (int i = 1; i < 2*n; ++i) {
			if(cmpVal[cmpId[var(i)]])
				printf("%s%d%c", s, i/2, i%2?'h':'w' ), s = " ";
		}
		printf("\n");
	}
	return 0;
}

