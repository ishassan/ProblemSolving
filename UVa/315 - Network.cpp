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
typedef long long ll;
using namespace std;

int n;
vector<vi> adjlst;
const int SIZE = 105;
int discovery[SIZE], back[SIZE], ind;
bool instack[SIZE];
set<int> res;
void articPoint(int root, int idx) {
	discovery[idx] = back[idx] = ind++;
	instack[idx] = 1;
	int sepchilds = 0;
	repi(it, adjlst[idx]) {

		if (instack[*it]) {
			back[idx] = min(back[idx], discovery[*it]);
		}

		else if (discovery[*it] == -1) {
			articPoint(root, *it);
			++sepchilds;
			if(back[*it] < discovery[idx])
				back[idx] = min(back[idx], back[*it]);
			else{
				if(idx!=root)
					res.insert(idx);
			}

			if (idx == root && sepchilds > 1) {
					res.insert(idx);
			}
		}
	}
	instack[idx] = 0;
}
int main() {

	string str;
	while (getline(cin, str)) {
		sstr ss(str);
		ss >> n;
		if (!n)
			break;
		adjlst.clear(), res.clear();
		adjlst.resize(n + 5);
		mem(discovery,-1), ind = 0;
		int f, t;

		while (getline(cin, str)) {
			ss.str(""), ss.clear();
			ss << str;
			ss >> f;
			if (!f)
				break;

			while (ss >> t) {

				adjlst[f].push_back(t);
				adjlst[t].push_back(f);
			}
		}

		repe(i,1,n) {
			if (discovery[i] == -1)
				articPoint(i, i);
		}

		printf("%d\n", sz(res));


	}

	return 0;
}
