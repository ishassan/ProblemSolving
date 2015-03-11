#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)
#define mp(a,b) make_pair(a,b)

int n;
pair<int, int> trees[17];
int memo[(1 << 17) + 9][17];

bool isline(int i, int j, int k) {
	pair<int, int> vij, vik; //vector from i to j, and from i to k
	 vij = mp(trees[j].first - trees[i].first,trees[j].second - trees[i].second);
	 vik = mp(trees[k].first - trees[i].first,trees[k].second - trees[i].second);

	 return vij.first * vik.second == vij.second * vik.first;

}

int DP(int mask, int rem) {
	if (rem <= 0)
		return 0;

	int &m = memo[mask][rem];
	if (m != -1)
		return m;

	int mini = 20;
	fo(i,n)
		if (!(mask & (1 << i))) {
			foo(j,i+1,n)
				if (!(mask & (1 << j))) {
					int msk = mask, r = rem;
					foo(k,j+1,n)
						if (!(mask & (1 << k))) {
							if (isline(i, j, k))
								mask |= (1 << k), rem--;
						}
					mini = min(mini, DP(mask | 1 << i | 1 << j, rem - 2) + 1);
					mask = msk, rem = r;
				}
		}

	if(mini == 20)
		mini = 1;
	return m = mini;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int tst, m, x, y;
	scanf("%d", &tst);
	tst++;
	foo(t,1,tst) {
		if (t > 1)
			printf("\n");
		printf("Case #%d:\n", t);
		scanf("%d%d", &n, &m);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		fo(i,n) {
			scanf("%d%d", &x, &y);
			trees[i] = mp(x,y);
		}
		memset(memo, -1, sizeof memo);
		printf("%d\n", DP(0, m));

	}

	return 0;

}
