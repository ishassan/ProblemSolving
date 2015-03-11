/*
 ID:fci_isl1
 LANG: C++
 TASK:agrinet
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

#define fo(i,n) for(int i=0; i<n;i++)
#define foo(i,a,n) for(int i=a; i<n;i++)
#define OO 1<<27

const int MAX =105;
int adjMax[MAX][MAX];
int MST(int n) {

	vector<int> vis(n, 0), dist(n, OO);
	dist[0] = 0; // we can reach source in no cost

	int mstCost = 0, cur = 0;
	for (int k = 0; k < n; k++) {
		vis[cur] = 1;
		int val = OO, idx = 0;
//relax all outside nodes with cur, and in same time find next cur
		for (int i = 0; i < n; i++) {
			if (vis[i])
				continue;

			if (adjMax[cur][i] < dist[i])
				dist[i] = adjMax[cur][i];

			if (dist[i] < val)
				val = dist[i], idx = i;
		}
		cur = idx;
		mstCost += dist[idx];
	}
	return mstCost;
}

int main(){
	freopen("agrinet.in","rt",stdin);
	freopen("agrinet.out","wt",stdout);

	int n;
	scanf("%d",&n);

	fo(i,n)
		fo(j,n)
			scanf("%d",&adjMax[i][j]);

	printf("%d\n",MST(n));

	return 0;

}
