#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
typedef long long ll;
using namespace std;


int main() {

	int n,m,a;
	scanf("%d%d%d",&n,&m,&a);

	ll w = (n+(a-1))/a;
	ll h = (m+(a-1))/a;

	cout<<w*h;
	return 0;
}
