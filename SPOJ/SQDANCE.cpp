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

struct DisjointSet {
	int parent[100004], rank[100004];
	DisjointSet(int n) {
		rep(i,n)
			parent[i] = i, rank[i] = 0;
	}

	int find(int n) {
		if (parent[n] == n)
			return n;
		return parent[n] = find(parent[n]);
	}

	bool join(int n1, int n2) {
		n1 = find(n1), n2 = find(n2);
		if (n1 == n2)
			return 0;
		if (rank[n1] >= rank[n2])
			parent[n2] = n1;
		else
			parent[n1] = n2;
		if(rank[n1]==rank[n2])
			++rank[n1];
		return 1;
	}
};
int main() {

	int tst,p,r,x,y;
	scanf("%d", &tst);
	while (tst--) {
		scanf("%d%d",&p,&r);
		DisjointSet s(p+1);
		int res=0;
		rep(i,r){
			scanf("%d%d",&x,&y);
			if(!s.join(x,y))
				++res;
		}
		printf("%d\n",res);
	}
	return 0;
}
