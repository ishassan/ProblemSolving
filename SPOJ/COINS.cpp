#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

map<int,ll> m;

ll DP(int n){
	if(m.find(n) != m.end())
		return m[n];

	ll res = n/2 + n/3 + n/4;

	if(res <= n)
		return m[n] = n;

	res =0;
	for(int i=2; i<5; i++)
		res += DP(n/i);

	return m[n] = res;
}
int main(){

#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int n;
	while(scanf("%d",&n) != -1)
		printf("%lld\n", DP(n));

	return 0;
}
