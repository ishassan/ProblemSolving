/*
 TASK: heritage
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

struct node {
	node*l, *r;
	char v;
};

node* build(string in, string pre) {
	if (in == "")
		return 0;
	fo(i,SZ(pre)) {
		int j;
		if ((j = in.find(pre[i])) != -1) {
			string lf=in.substr(0,j);
			string rt=in.substr(j+1);
			node *n=new node;
			n->v=pre[i];
			n->l=build(lf,pre.substr(i+1));
			n->r=build(rt,pre.substr(i+1));
			return n;
		}
	}
}

void print(node*n)
{
	if(n)
	{
		print(n->l);
		print(n->r);
		cout<<n->v;
	}
}
int main() {
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	string in,pre;
	cin>>in>>pre;
	print(build(in,pre));
	cout<<endl;
	return 0;
}
