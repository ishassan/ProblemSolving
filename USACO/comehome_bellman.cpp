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

const int SIZE = 300;
int dist[SIZE];
int p;
struct Edge {
	int from, to, cst;
	Edge(int f, int t, int c) {
		from = f, to = t, cst = c;
	}
	Edge() {
	}
} edges[20004];

void bellman(int src) {
	fill(dist, dist + SIZE, 1e6);
	dist[src]=0;
	for (int cnt = 0; cnt < SIZE; ++cnt) {
		for (int i = 0; i < p; ++i) {
			if(dist[edges[i].from] + edges[i].cst < dist[edges[i].to])
				dist[edges[i].to] = dist[edges[i].from] + edges[i].cst;
		}
	}
}

int main() {

	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);

	scanf("%d", &p), p *=2;
	set<char> up;
	rep(i,p) {
		char s, d;
		int dst;
		scanf(" %c %c%d", &s, &d, &dst);
		if (isupper(s))
			up.insert(s);
		if (isupper(d))
			up.insert(d);

		edges[i] = Edge(s, d, dst);
		edges[++i] = Edge(d, s, dst);
	}

	//25 = 'Z' - 'A'

	bellman('Z');
	char mn;
	int Mn = 1e5;
	repi(it,up) {
		if (*it != 'Z' && Mn > dist[*it]) {
			Mn = dist[*it];
			mn = *it;
		}
	}

	printf("%c %d\n", mn, Mn);
	return 0;
}
