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

bool graph[21][21];
long long memo[(1<<20) +2];
int n;

long long DP(int bit, int st){
	long long &m = memo[bit];
	if(st == n)
		return 1;

	if(m!= -1)
		return m;

	long long count =0;
	for (int j = 0; j < n; ++j)
		if(graph[st][j] && !((bit>>j) & 1))
			count += DP(bit | (1<<j) , st+1);

	return m = count;
}
int main(){
	int tst;
	scanf("%d",&tst);
	while(tst--){
		scanf("%d",&n);
		fo(i,n)
			fo(j,n)
				scanf("%d",&graph[i][j]);

		memset(memo,-1 ,sizeof memo);
		printf("%lld\n",DP(0,0));
	}
	return 0;
}
