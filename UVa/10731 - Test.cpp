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
#include <hash_map>

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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

const int SIZE=300;
int n;
vector<vc> adjlst;
int Index[SIZE],lowlink[SIZE];
bool instack[SIZE];
stack<char> stk;
set<set<char> > sol;
bool Free[SIZE];
int ind;
void SCC(char idx){
	Index[idx] = lowlink[idx] = ind++;
	instack[idx]=1;
	stk.push(idx);

	repi(it, adjlst[idx]){
		if(instack[*it]){
			lowlink[idx] = min(lowlink[idx], lowlink[*it]);
		}
		else if(Index[*it]==-1){
			SCC(*it);
			lowlink[idx] = min(lowlink[idx], lowlink[*it]);
		}
	}

	if(Index[idx]==lowlink[idx]){
		set<char> ans;
		char tp;
		do{
			tp = stk.top();
			stk.pop();
			instack[tp]=0;
			ans.insert(tp);
			Free[tp]=0;
		}while(tp != idx);
		sol.insert(ans);
	}
}
int main() {

//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);

	char* endl="";
	while(scanf("%d",&n) && n){
		printf("%s",endl), endl="\n";
		char x[5],y;
		adjlst.clear();
		adjlst.resize(SIZE);
		mem(Index,-1);
		mem(Free,-1);
		sol.clear();
		ind=0;
		set<char> inp;
		rep(i,n){
			scanf(" %c %c %c %c %c %c",&x[0],&x[1],&x[2],&x[3],&x[4],&y);
			rep(j,5)
				adjlst[y].push_back(x[j]), inp.insert(y), inp.insert(x[j]);
		}

		repi(it, inp){
			if(Index[*it]==-1){
				SCC(*it);
			}
			if(Free[*it]){
				set<char> s;
				s.insert(*it);
				sol.insert(s);
			}
		}

		repi(i, sol){
			char* str = "";
			repi(j, (*i)){
				printf("%s%c",str,*j);
				str=" ";
			}
			printf("\n");
		}
	}
	return 0;
}
