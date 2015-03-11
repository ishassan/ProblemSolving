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


int mat[802][802];
int main() {

	int tst = 0, n;
	while (scanf("%d", &n) && n) {
		int c = 1;
		rep(i,n) {
			repe(j,1,c) {
				scanf("%d", &mat[i][j]);
				mat[i][j] += mat[i][j - 1];
			}
			c += 2;
		}
		c = 1;
		ll res = -1LL << 62;
		rep(i,n) {
			repe(j,1,c) {
				ll sum = 0;
				int l = j, r = j;
				if (j % 2)
					reps(ii,i,n) {
						sum += mat[ii][r]-mat[ii][l-1];
						res = max(res,sum);
						r+=2;
					}
				else{
					int curc=c;
					for (int ii = i; ii>=0; --ii) {
						sum += mat[ii][r]-mat[ii][l-1];
						res = max(res,sum);
						l-=2,curc-=2;
						if(!l || r>=curc)
							break;
					}
				}
			}
			c+=2;
		}
		printf("%d. %lld\n",++tst,res);
	}
	return 0;
}
