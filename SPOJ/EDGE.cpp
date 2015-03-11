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

int Ax[4] = { 0, -10, 0, 10 };
int Ay[4] = { -10, 0, 10, 0 };
int Vx[4] = { 0, -10, 0, 10 };
int Vy[4] = { 10, 0, -10, 0 };
int main() {
	char str[210];
	while (scanf("%s", str) != -1) {
		printf("300 420 moveto\n310 420 lineto\n");
		int idx = 0,x = 310, y = 420;
		int isA=-1;	//if the prev char is A 1 else V 0 else -1
		for (int i = 0; str[i]; ++i) {
			if (str[i] == 'A') {
				if (isA==0)
					idx = 3 - (idx + 3)%4;	//3 - (idx-1+4)%4
				isA = 1;
				x += Ax[idx], y += Ay[idx];
			} else {
				if (isA==1)
					idx = 3 - (idx + 3)%4;
				isA = 0;
				x += Vx[idx], y += Vy[idx];
			}
			printf("%d %d lineto\n", x, y);
			idx = (idx + 1) % 4;
		}
		printf("stroke\nshowpage\n");
	}

	return 0;
}
