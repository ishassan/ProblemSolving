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
#include <hash_map>
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
using namespace __gnu_cxx;

hash_map<int,int> m;
int getNext(int n){
	int res=0,dig;
	while(n){
		dig = n%10;
		res += dig*dig;
		n/=10;
	}
	return res;
}
int main() {

	int n,steps=0;
	scanf("%d",&n);
	m[n] = steps++;
	while(n>1){
		int nxt = getNext(n);
		if(m.find(nxt)!=m.end()){
			printf("-1\n");
			return 0;
		}
		m[nxt]=steps++;
		n = nxt;
	}
	printf("%d\n",steps-1);
	return 0;
}
