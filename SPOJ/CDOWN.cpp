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
#define rrepi(it,stl) for(typeof((stl).rbegin()) it = (stl).rbegin(); (it)!=stl.rend(); ++(it))
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


int n,d;
map<string,set<string> > m;

int dfs(string name, int d){
	if(d==0)
		return 1;

	set<string> s = m[name];
	int r =0;

	repi(it,s)
	{
		r += dfs(*it, d-1);
	}

	return r;
}

int main() {

	int tst;
	scanf("%d",&tst);
	repe(t,1,tst){
		scanf("%d%d",&n,&d);
		m.clear();

		string name,subname;
		int c;
		rep(i,n){
			cin>>name>>c;
			rep(j,c){
				cin>>subname;
				m[name].insert(subname);
			}
		}

		map<int, set<string> > res;
		repi(it,m){
			res[ dfs(it->first,d ) ].insert(it->first);
		}

		cout<<"Tree "<<t<<":\n";
		c =0;
		rrepi(num,res){
			if(num->first == 0)
				break;

			repi(str, num->second){
				cout<<*str<<" "<<num->first<<endl;
				c++;
			}

			if(c>=3)
				break;
		}

	}

	return 0;
}
