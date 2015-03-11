/*
 ID: fci_isl1
 LANG: C++
 PROB: comehome

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

const int SIZE = 60;
int graph[SIZE][SIZE];
int memo[SIZE][SIZE][SIZE];

int floydRecursive(int i, int j, int k) {
	if (k == -1)
		return graph[i][j];
	int& m = memo[i][j][k];
	if (m != -1)
		return m;

	return m = min(floydRecursive(i, j, k - 1), floydRecursive(i, k, k - 1)
			+ floydRecursive(k, j, k - 1));
}

int getID(char c) {
	if (isupper(c))
		return c - 'A';
	else
		return c - 'a' + 26;
}

char setID(int n) {
	if (n < 26)
		return n + 'A';
	else
		return n - 26 + 'a';
}
int main() {

	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);

	rep(i,SIZE)
		rep(j,SIZE)
			graph[i][j] = 1e5;

	mem(memo,-1);
	int p;
	scanf("%d", &p);
	set<int> up;
	rep(i,p) {
		char s, d;
		int dst;
		scanf(" %c %c%d", &s, &d, &dst);
		int sid = getID(s), did = getID(d);
		if (isupper(s))
			up.insert(sid);
		if (isupper(d))
			up.insert(did);
		graph[did][sid] = graph[sid][did] = min(graph[sid][did], dst);
	}

	//25 = 'Z' - 'A'

	repi(it,up) {
		if (*it != 25)
			floydRecursive(*it, 25, SIZE - 2);

	}

	char mn;
	int Mn = 1e5;
	repi(it,up) {

		if (*it != 25 && Mn > memo[*it][25][SIZE - 2]) {
			Mn = memo[*it][25][SIZE - 2];
			mn = setID(*it);
		}

	}

	printf("%c %d\n", mn, Mn);
	return 0;
}
