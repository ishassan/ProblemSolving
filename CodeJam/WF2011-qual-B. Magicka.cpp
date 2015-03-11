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

char comp[300][300];
vector<vector<char> > opp;
vector<char> res;
int vis[300];

bool isOpp(char ch){
	repi(it, opp[ch]){
		if(vis[*it])
			return 1;
	}
	return 0;
}
int main() {

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	int tst,ncmp,nopp,n;
	scanf("%d",&tst);
	repe(t,1,tst){
		res.clear();
		opp.clear();
		opp.resize(300);
		mem(comp,0);
		mem(vis,0);

		scanf("%d",&ncmp);
		char str[105];
		rep(i,ncmp){
			scanf("%s",str);
			comp[str[0]][str[1]]=str[2];
			comp[str[1]][str[0]]=str[2];
		}

		scanf("%d",&nopp);
		rep(i,nopp){
			scanf("%s",str);
			opp[str[0]].push_back(str[1]);
			opp[str[1]].push_back(str[0]);
		}

		scanf("%d",&n);
		scanf("%s",str);
		rep(i,n){
			if(res.size()==0){
				res.push_back(str[i]);
				++vis[str[i]];
				continue;
			}

			char lst = res[sz(res)-1];
			if(comp[str[i]][lst]){
				vis[lst] = max(0, vis[lst]-1);
				res.erase(res.end()-1);
				res.push_back(comp[str[i]][lst]);
				++vis[comp[str[i]][lst]];
			}

			else if(isOpp(str[i])){
				res.clear();
				mem(vis,0);
			}

			else{
				res.push_back(str[i]);
				++vis[str[i]];
			}

		}

		printf("Case #%d: [",t);
		rep(i,sz(res)){
			printf("%c",res[i]);
			if(i+1<sz(res))
				printf(", ");
		}
		printf("]\n");
	}
	return 0;
}
