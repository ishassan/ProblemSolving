#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>


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

pii pnt[2500];
ll slope[2500] = {0};

int main() {

	int tst,n;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d",&n);

		rep(i,n)
			scanf("%d%d",&pnt[i].first, &pnt[i].second);

		sort(pnt, pnt + n);

		int mx=(n)?1:0;

		rep(i,n){
			int idx=0;
			int ver=0;
			reps(j,i+1,n){
				int xdiff = pnt[j].first - pnt[i].first;
				int ydiff = pnt[j].second - pnt[i].second;

				if(ydiff == 0)
					ver++;

				else{
					ll r = xdiff * 100000ll / ydiff;
					slope[idx++] = r;
				}
			}

			sort(slope,slope+idx);
			mx = max(mx,ver);
			int r =1;
			reps(j,1,idx){
				if(slope[j] == slope[j-1])
					r++;
				else
					r = 1;
				mx = max(mx,r);
			}

		}

		printf("%d\n",mx);
	}
	return 0;
}
