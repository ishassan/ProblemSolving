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
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define vit list<pair<int, pii> >::iterator
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

struct hashString{
	size_t operator()(const string& s)const{
		return hash<const char*>()(s.c_str());
	}
};

int n, m;

hash_map<string, int, hashString> Map;

const int SIZE = 105;
vector<vi> adjlst;
int Index[SIZE], lowlink[SIZE];
set<int> pnts;
int ind;
void artPoints(int root, int idx) {
	Index[idx] = lowlink[idx] = ind++;
	int sepchild = 0;
	repi(it, adjlst[idx]) {

		if (Index[*it] == -1) {
			artPoints(root, *it);
			lowlink[idx] = min(lowlink[idx], lowlink[*it]);
			sepchild++;
			if (idx != root && Index[idx] <= lowlink[*it])
				pnts.insert(idx);
			else if (idx == root && sepchild > 1)
				pnts.insert(idx);
		}
		lowlink[idx] = min(lowlink[idx], Index[*it]);
	}
}

// calling
// rep(i,n)
//	 if (Index[i] == -1)
//	    	artPoints(i, i);
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	char* endl = "";
	int tst = 0, a, b;
	while (scanf("%d", &n) && n) {
		Map.clear();
		adjlst.clear(), pnts.clear();
		adjlst.resize(n + 5);
		mem(Index,-1);
		ind = 0;
		printf("%s", endl), endl = "\n";
		string str, str2;
		string city[SIZE];
		rep(i,n) {
			cin >> str;
			Map[str] = i;
			city[i] = str;
		}

		scanf("%d", &m);
		rep(i,m) {
			cin >> str >> str2;
			a = Map[str], b = Map[str2];
			adjlst[a].push_back(b);
			adjlst[b].push_back(a);
		}

		rep(i,n)
			if (Index[i] == -1)
				artPoints(i, i);

		printf("City map #%d: %d camera(s) found\n", ++tst, pnts.size());

		set<string> res;
		repi(it,pnts)
			res.insert(city[*it]);

		repi(it, res)
			cout << *it << endl;

	}

	return 0;
}

