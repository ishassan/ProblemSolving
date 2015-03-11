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
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int r,c;
int mi,mj,ci,cj,cci,ccj;

bool check(int i, int j){
	int mouse = abs(mi-i) + abs(mj-j);
	int cat1 = abs(ci-i) + abs(cj-j);
	int cat2 = abs(cci-i) + abs(ccj-j);

	return (mouse < cat1 && mouse < cat2);
}
int main() {
	int tst;
	scanf("%d%d%d",&r,&c,&tst);
	while(tst--){

		scanf("%d%d%d%d%d%d",&mi,&mj,&ci,&cj,&cci,&ccj);
		bool can = false;
		can |= check(1,mj);
		can |= check(r,mj);
		can |= check(mi,1);
		can |= check(mj,c);
		printf((can)?"YES\n":"NO\n");
	}

	return 0;
}
