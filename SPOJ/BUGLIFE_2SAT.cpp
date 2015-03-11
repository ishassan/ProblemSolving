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
#include <list>
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
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define vit list<pair<int, pii> >::iterator
typedef long long ll;
using namespace std;

vector<vi> adjlst;
int n,m;
const int SIZE=4005;

int Index[SIZE], lowlink[SIZE], compIndex[SIZE];	//compIndex[node] = compid
bool instack[SIZE];
stack<int> stk;
int ind;

int compid;
void tarjan(int idx){
	Index[idx] = lowlink[idx] = ind++;
	instack[idx]=1;
	stk.push(idx);

	rep(i,sz(adjlst[idx])){
		int nxt = adjlst[idx][i];
		if(Index[nxt]==-1){
			tarjan(nxt);
			lowlink[idx] = min(lowlink[idx], lowlink[nxt]);
		}
		else if(instack[nxt])
			lowlink[idx] = min(lowlink[idx], lowlink[nxt]);
	}

	if(Index[idx]==lowlink[idx]){
		int tp;
		do{
			tp = stk.top();
			stk.pop();
			instack[tp]=0;
			compIndex[tp] = compid;
		}while(tp != idx);
		++compid;
	}
}
int main() {

	int tst;
	scanf("%d",&tst);
	repe(t,1,tst){
		scanf("%d%d",&n,&m);
		adjlst.clear();
		adjlst.resize(n+n+5);
		mem(Index,-1), mem(instack,0), mem(compIndex,0);
		rep(i,SIZE)
			lowlink[i]=i;
		ind=compid=0;
		int a,b;
		rep(i,m){
			scanf("%d%d",&a,&b);
			--a,--b;	//a+n = !a
			adjlst[a].push_back(n+b);
			adjlst[b].push_back(n+a);
			adjlst[a+n].push_back(b);
			adjlst[b+n].push_back(a);
		}

		rep(i,n+n){
			if(Index[i]==-1)
				tarjan(i);
		}

		bool valid=1;
		rep(i,n)
			if(compIndex[i]==compIndex[n+i]){
				valid=0;
				break;
			}

		printf("Scenario #%d:\n",t);
		if(valid)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}

