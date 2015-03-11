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
#include <list>
#include <climits>
#include <assert.h>
#include <map>

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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

int n;

int arr[20];
int sol[6];

void print(){
	char* s="";
	rep(i,6)
		printf("%s%d",s,sol[i]), s=" ";
	printf("\n");
}
void comb(int idx, int taken){
	if(taken==6){
		print();
		return;
	}
	if(idx==n)
		return;

	sol[taken] = arr[idx];
	comb(idx+1,taken+1);
	comb(idx+1,taken);

}
int main() {

//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);

	char* endl="";
	while(scanf("%d",&n) && n){
		printf("%s",endl), endl="\n";
		rep(i,n)
				scanf("%d",arr+i);
		comb(0,0);
	}

	return 0;
}
