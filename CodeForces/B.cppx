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
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())

typedef long long ll;
using namespace std;

double calc(double r1, double r2){
	return M_PI*r1*r1 - M_PI*r2*r2;
}
int main() {
//1 2 3 4 = 31
	int n;
	int radii[102];
	scanf("%d",&n);
	rep(i,n)
		scanf("%d",radii+i);

	sort(radii,radii+n);
	double res=0;
	for (int i = n-1; i-1 >=-1; i-=2) {
		if(i==0)
			res += calc(radii[i],0);
		else
			res += calc(radii[i],radii[i-1]);
	}
	printf("%.15lf",res);

	return 0;
}
