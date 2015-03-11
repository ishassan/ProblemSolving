/*
 TASK: shopping
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

vector<pii> offer[100];
vector<pair<pii, int> > req;
int memo[(1 << 15) + 5];
map<int, int> Map;

int noffer, nprod;

void setBit(int& mask, int idx, int bit) {
	if (bit)
		mask = mask | (1 << idx);
	else
		mask = mask & (~(1 << idx));

}
int DP(int mask) { //1 product = 3 bits

	if (!mask)
		return 0;

	if (memo[mask] != -1)
		return memo[mask];

	int mini = 1e9;
	fo(i,noffer) {
		int tmp = mask;
		fo(j,SZ(offer[i])-1) {
			int newid = Map[offer[i][j].first];
			int newq = ((tmp >> (3 * newid)) & 7);
			if (newq - offer[i][j].second < 0) {
				tmp = mask;
				break;
			}

			newq -= offer[i][j].second;
			setBit(tmp, 3 * newid, newq & 1);
			setBit(tmp, 3 * newid + 1, (newq & 2) >> 1);
			setBit(tmp, 3 * newid + 2, (newq & 4) >> 2);

		}

		if (tmp != mask)
			mini = min(mini, DP(tmp) + offer[i].back().first);
	}

	fo(i,SZ(req)) {
		int tmp = mask;

		int newid = Map[req[i].first.first];
		int newq = (tmp >> (3 * newid)) & 7;
		if (newq <= 0)
			continue;

		newq--;
		setBit(tmp, 3 * newid, newq & 1);
		setBit(tmp, 3 * newid + 1, (newq & 2) >> 1);
		setBit(tmp, 3 * newid + 2, (newq & 4) >> 2);
		mini = min(mini, DP(tmp) + req[i].second);
	}

	return memo[mask] = mini;

}
int main() {
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);

	int cnt = 0;
	scanf("%d", &noffer);
	fo(i,noffer) {
		int n, p;
		scanf("%d", &n);
		while (n--) {
			int id, k;
			scanf("%d%d", &id, &k);
			offer[i].push_back(mp(id,k));
			if (Map.find(id) == Map.end())
				Map[id] = cnt++;
		}

		scanf("%d", &p);
		offer[i].push_back(mp(p,0));
	}

	scanf("%d", &nprod);
	fo(i,nprod) {
		int id, k, p;
		scanf("%d%d%d", &id, &k, &p);
		req.push_back(mp(mp(id,k) , p));
		if (Map.find(id) == Map.end())
			Map[id] = cnt++;
	}
	int mask = 0;
	for (int i = nprod - 1; i >= 0; i--) {
		mask = (mask << 3);
		mask |= req[i].first.second; //quantity
	}

	memset(memo, -1, sizeof memo);

	printf("%d\n", DP(mask));
	return 0;
}
