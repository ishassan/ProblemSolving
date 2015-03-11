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


int main() {

	int n,x,v;
	vector<int> vv;
	scanf("%d%d",&n,&x);
	rep(i,n)
	{
		scanf("%d",&v);
		vv.push_back(v);
	}
	sort(all(vv));
	int i;
	int mid = (sz(vv)+1)/2;
	if(vv[mid-1] == x){
		cout<<0;
		return 0;
	}
	for (i = 1; i <= n+3; i++) {
		vv.push_back(x);
		sort(all(vv));
		int mid = (sz(vv)+1)/2;
		if(vv[mid-1] == x)
			break;
	}
	cout<<i;
	return 0;
}
