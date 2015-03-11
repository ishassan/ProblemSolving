/*
TASK:
LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO=0;
const long double INF=1/ZERO,EPSILON=1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))


#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
bool isPrime[1<<16];
int s;
int primes[1<<16];
bool isprime(int x)
{
	if(x<2)
		return false;
	rep(i,s)
		if(primes[i]*primes[i]>x)
			break;
		else
			if(x%primes[i]==0)
				return false;
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in","rt",stdin);
	freopen("1.out","wt",stdout);
#endif
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0]=isPrime[1]=0;
	for(int i=0;i*i<=1000000000;i++)
	{
		if(isPrime[i])
		{
			primes[s++]=i;
			for(int j=i*i;j*(long long)j<=1000000000;j+=i)
				isPrime[j]=0;
		}
	}
	int t;
	scanf("%d",&t);
	char *sp="";
	while(t--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		printf(sp);
		rep2(i,m,n)
		{
			if(isprime(i))
				printf("%d\n",i);
		}

		sp="\n";
	}
	return 0;
}
