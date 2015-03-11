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
#include <pthread.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define rrepi(it,stl) for(typeof((stl).rbegin()) it = (stl).rbegin(); (it)!=stl.rend(); ++(it))
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

map<int,int> vis1,vis2;

int calc(int num) {
	int res = 0;
	while (num) {
		int dig = num % 10;
		res += dig * dig;
		num /= 10;
	}
	return res;
}

int BFS(int n, int m) {

	if (n == m)
		return 2;

	int step1 = 1, step2 = 1;
	vi res1,res2;

	res1.push_back(n);
	res2.push_back(m);
	vis1[n] = step1++;
	vis2[m] = step2++;

	while (true) {
		int newn = calc(n);

		if (vis1[newn])
			break;

		vis1[newn] = step1++;
		n = newn;
		res1.push_back(newn);
	}

	while (true) {
		int newm = calc(m);

		if (vis2[newm])
			break;

		vis2[newm] = step2++;
		m = newm;
		res2.push_back(newm);
	}

	int r = 1<<30;

	rep(i,sz(res1)){
		if(vis2[res1[i]])
			r = min(r, (i+1) + vis2[res1[i]] );
	}

	return (r==1<<30)?0:r;
}
int main() {


	int n, m;
	while (scanf("%d%d", &n, &m) && (m || n)) {
		vis1.clear();
		vis2.clear();
		printf("%d %d %d\n", n, m, BFS(n, m));
	}

	return 0;
}
