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
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())

typedef long long ll;
using namespace std;

pair<int,int> cnt[100003];
bool cand[100003];
vector<pair<char,int> > g;
int main() {

	int n,m,x,pos=0,neg=0;
	scanf("%d%d",&n,&m);
	g.resize(n);
	rep(i,n){
		char c;
		scanf(" %c %d",&c, &x);
		g[i] = make_pair(c,x-1);
		if(c == '+'){
			pos++;
			cnt[x-1].first++;
		}
		else{
			neg++;
			cnt[x-1].second++;
		}
	}

	int ncand=0;
	rep(i,n){
		int tru = cnt[i].first + (neg - cnt[i].second);
		if(tru == m) cand[i]=1,++ncand;
	}

	rep(i,n){
		int glty = g[i].second;
		// 0,1 && +,- && 1,>
		if(cand[glty]){
			if(ncand > 1) printf("Not defined\n");
			else if(g[i].first == '+') printf("Truth\n");
			else printf("Lie\n");
		}
		else if(g[i].first == '+')
			printf("Lie\n");
		else if(g[i].first == '-')
			printf("Truth\n");
	}

	return 0;
}
