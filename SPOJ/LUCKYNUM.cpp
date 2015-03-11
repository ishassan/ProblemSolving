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
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

struct state {
	int par, mod, last;
	state() {
	}
	state(int p, int m, int l) {
		par = p, mod = m, last = l;
	}
};

vector<state> states;

void print(int idx){
	if(idx==-1)
		return;
	print(states[idx].par);
	printf("%d",states[idx].last);
}
void BFS(int n) {
	states.push_back(state(-1, 6%n, 6));
	states.push_back(state(-1, 8%n, 8));
	int steps = 0;
	int idx = 0;
	while(idx < sz(states) && steps<=200) {

		int len = sz(states) - idx;
		while (len--) {
			state st = states[idx];
			if (st.mod == 0)
				goto end;

			state ns1 = state(idx, (st.mod * 10+6) % n, 6);
			states.push_back(ns1);
			if (st.last == 8) {
				state ns2 = state(idx, (st.mod * 10+8) % n, 8);
				states.push_back(ns2);
			}
			++idx;
		}
		++steps;
	}
	end: ;
	if (steps <= 200 && states[idx].mod == 0)
		print(idx);
	else
		printf("-1");
}
int main() {

	int tst, n;
	scanf("%d", &tst);
	while (tst--) {
		states.clear();
		scanf("%d", &n);
		BFS(n);
		printf("\n");
	}

	return 0;
}
