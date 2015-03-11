/*
 TASK: fence9
 LANG: C++
 ID: fci_isl1
 */

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
#include <valarray>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define foi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define SZ(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;



int main() {
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);
	int n,m,p;
	cin>>n>>m>>p;
	int a=(p*m)/2;	//a == area
	int b=__gcd(n,m)+p+abs(__gcd(p-n,m)); //calc number of lattice points on boundry
	//__gcd(n,m) ==> line(0,0) to (n,m)
	//p ==> 0,0 to p,0
	//third: p,0 to n,m
	cout<<a-b/2+1<<endl;	//area - lattice points on boundry
	return 0;
}
