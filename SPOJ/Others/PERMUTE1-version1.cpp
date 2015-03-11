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
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef stringstream sstr;

int n;
int memo[(1<<13)+9][99];
int inv[1<<13][15];
int check(int bit, int n){
	int res=0;
	int i=0;
	while(bit>0){
		if(bit&1 &&i>n)
			res++;

		bit = bit>>1, i++;
	}
	return res;
}
int dp(int counter,int bit, int remInv) {
	if(memo[bit][remInv]!= -1)
		return memo[bit][remInv];

	if(counter==n){
		if(remInv==0)
			return memo[bit][remInv] =1;
		return memo[bit][remInv] =0;
	}
	int res =0;
	for(int i=1; i<=n; i++){
		if((bit>>i)&1)
			continue;

		int inv = check(bit,i);
		if( inv > remInv)
			continue;

		res += dp(counter+1,bit | (1<<i) , remInv-inv);
	}
	return memo[bit][remInv] =res;
}
int main() {

	int tst;
	scanf("%d",&tst);
	while(tst--){
		int k;
		scanf("%d %d",&n,&k);
		memset(memo,-1,sizeof memo);
		printf("%d\n",dp(0,0,k));
	}

	return 0;
}
