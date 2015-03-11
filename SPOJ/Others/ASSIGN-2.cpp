/*
 * 423_ASSIGN.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: Jul 2, 2009
 */


#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef long long         ll;
typedef long double   	  ld;

const int OO = (int)1e8;	//Small -> WRONG, Large -> OVERFLOW

const double PI  = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

vector< vector<int> > adjList;

ll memo[1<<20];
int n;

/*
ll go(int i, int mask) {	// i is redundant information
	if(i == n) {
		if(mask == (1<<n)-1)	return 1;
		return 0;
	}

	ll &ret = memo[i][mask];
	if(ret != -1)	return ret;

	ret = 0;
	rep(j, adjList[i]) {
		int k = adjList[i][j];

		if( ((mask>>k)&1) == 0) {
			ret += go(i+1, mask | 1<<k);
		}
	}

	return ret;
}
*/
//number of ones = idx, so do not memoize it, BUT send it to not need to generate it
ll go(int mask, int i = 0) {

	//if ur base case cost time, make sure to check memo 1st

	ll &ret = memo[mask];
	if(ret != -1)	return ret;

	if(i == n)	return 1;

	ret = 0;
	rep(j, adjList[i]) {
		int k = adjList[i][j];

		if( ((mask>>k)&1) == 0) {
			ret += go(mask | 1<<k, i+1);
		}
	}

	return ret;
}



int main()
{
	/*
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
#endif
*/
	int cases;

	scanf("%d", &cases);

	while(cases--) {

		scanf("%d", &n);

		adjList.clear();
		adjList.resize(n);

		lp(i, n) {
			int bit;
			lp(j, n) {
				scanf("%d", &bit);
				if(bit)
					adjList[i].push_back(j);
			}
		}
		clr(memo, -1);
		cout<<go(0)<<"\n";
	}

	return 0;
}

