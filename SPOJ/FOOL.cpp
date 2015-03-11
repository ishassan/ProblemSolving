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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

char str[202];
int len;
int smemo[202][202];
int lmemo[202][202];

int isSet(int s, int e);

int iselem(int s, int e){
	if(s > e)
		return 0;
	if(s==e)
		return str[s]=='{' || str[s]=='}' || str[s]==',';

	return isSet(s,e);
}
int islist(int s, int e){
	int& m = lmemo[s][e];
	if(m != -1)
		return m;
	if(s > e)
		return m=0;
	if(iselem(s,e))
		return m=1;

	repe(i,s,e){
		if(str[i]==',')
			if(iselem(s,i-1) && islist(i+1,e))
				return m=1;
	}

	return m=0;
}

int isSet(int s, int e){
	int& m = smemo[s][e];
	if(m != -1)
		return m;
	if(s > e)
		return m=0;
	if(str[s]!='{' || str[e]!='}')
		return m=0;

	if(s+1==e)	//empty
		return m=1;

	return m=islist(s+1,e-1);
}

int main() {

	int tst;
	scanf("%d", &tst);
	repe(t,1,tst) {
		scanf("%s", str);
		len = strlen(str);
		mem(smemo,-1);
		mem(lmemo,-1);
		printf("Word #%d: ",t);
		if(isSet(0,len-1))
			printf("Set\n");
		else
			printf("No Set\n");
	}

	return 0;
}
