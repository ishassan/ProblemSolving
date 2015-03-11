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

int main() {

	//There are two constrains:
	// the bottom part should cover the Circumference of circle
	// the diameter of circle <= width of paper

	int w, h;
	while (scanf("%d%d", &w, &h) && (h || w)) {
		// first case: height is the width of bottom part
		// 2*PI*r <= h-2r && 2r <= w
		// so

		double r = min(w / 2.0, h / (2.0 * M_PI + 2));
		double height = w;
		double vol = M_PI * r * r * height;

		//second case: height is the length of bottom part
		//2*PI*r<=w && 2r<=w
		//so
		r = w / (2.0 * M_PI);
		height = h - 2 * r;
		vol = max(vol, M_PI * r * r * height);

		printf("%.3lf\n", vol);

	}

	return 0;
}
