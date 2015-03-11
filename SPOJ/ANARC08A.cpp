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
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif


hash_map<ll, int, hash<int> > sol;

void setNum(ll& grid, int num, int pos) {
	//clear
	ll tmp = 15LL << pos;
	tmp = ~tmp;
	grid &= tmp;

	//set
	grid |= (num*1LL) << pos;
}

ll mvRt(ll grid, int i, int j) {
	int pos = i * 3 + j;
	int cur = grid & (15 << (pos * 4));
	cur = (cur >> (pos * 4));

	int right = grid & (15 << ((pos + 1) * 4));
	right = (right >> ((pos + 1) * 4));

	ll down = grid & (15LL << ((pos + 3) * 4));
	down = (down >> ((pos + 3) * 4));

	ll dright = grid & (15LL << ((pos + 4) * 4));
	dright = (dright >> ((pos + 4) * 4));

	int tmp = cur;
	cur = down;
	down = dright;
	dright = right;
	right = tmp;

	setNum(grid, cur, pos * 4);
	setNum(grid, right, (pos + 1) * 4);
	setNum(grid, down, (pos + 3) * 4);
	setNum(grid, dright, (pos + 4) * 4);

	return grid;
}

ll mvLf(ll grid, int i, int j) {
	int pos = i * 3 + j;
	int cur = grid & (15 << (pos * 4));
	cur = (cur >> (pos * 4));

	int right = grid & (15 << ((pos + 1) * 4));
	right = (right >> ((pos + 1) * 4));

	ll down = grid & (15LL << ((pos + 3) * 4));
	down = (down >> ((pos + 3) * 4));

	ll dright = grid & (15LL << ((pos + 4) * 4));
	dright = (dright >> ((pos + 4) * 4));
	if (dright < 0)
		dright &= 15;

	int tmp = cur;
	cur = right;
	right = dright;
	dright = down;
	down = tmp;

	setNum(grid, cur, pos * 4);
	setNum(grid, right, (pos + 1) * 4);
	setNum(grid, down, (pos + 3) * 4);
	setNum(grid, dright, (pos + 4) * 4);

	return grid;
}

void generateAll(ll cur) {
	queue<ll> q;
	q.push(cur);
	sol[cur] = 0;
	int steps = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			cur = q.front();
			q.pop();

			rep(i,2)
				rep(j,2) {
					ll nxt = mvRt(cur, i, j);
					if (sol.find(nxt) == sol.end()) {
						sol[nxt] = steps;
						q.push(nxt);
					}

					nxt = mvLf(cur, i, j);
					if (sol.find(nxt) == sol.end()) {
						sol[nxt] = steps;
						q.push(nxt);
					}
				}
		}
		steps++;
	}
}
int main() {

	ll goal = 0;
	reps(i,1,10) {
		goal |= (i * 1LL) << ((i - 1) * 4); //write in 4 digits
	}
	generateAll(goal);

	int tst = 1;
	char str[11];

	while (scanf("%s", str) && str[1] != '0') {
		int steps = str[0] - '0';
		goal = 0;
		reps(i,1,10)
			goal |= ((str[i] - '0') * 1LL) << ((i - 1) * 4);

		printf("%d. ", tst++);
		if (sol.find(goal) == sol.end())
			printf("-1\n");
		else if (sol[goal] > steps)
			printf("-1\n");
		else
			printf("%d\n", sol[goal]);
	}
	return 0;
}
