/*
 TASK: game1
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

int memo[101][101];
int arr[101];
int calc(int i,int j)
{
	if(j<i)
		return 0;
	int&r=memo[i][j];
	if(r!=1e6)return r;
	return r=max(arr[i] -calc(i+1,j),arr[j] -calc(i,j-1));

}
int main() {
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	fill((int*)memo,(int*)memo+101*101,1e6);
	int n;
	cin>>n;
	int s=0;
	fo(i,n)
		cin>>arr[i],s+=arr[i];
	int d=calc(0,n-1);
	//a+b=s;
	//a-b=d;
	//2a=s+d
	int a=(s+d)/2;
	int b=s-a;
	cout<<a<<" "<<b<<endl;

	return 0;
}
