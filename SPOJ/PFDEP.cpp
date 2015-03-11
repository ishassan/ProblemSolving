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

int n, m;

const int SIZE = 105;
vector<vector<int> > outNodes(SIZE);
vector<vector<int> > inNodes(SIZE);
vector<int> output;

void topologicalSort() { // 1 based
	output.clear();
	vector<int> outDegree(n + 1);

	for (int i = 1; i <= n; ++i)
		outDegree[i] = sz(outNodes[i]);

	set<int> zeros;

	for (int i = 1; i <= n; ++i)
		if (outDegree[i] == 0)
			zeros.insert(i);

	while (zeros.size()) {
		int cur = *zeros.begin();
		zeros.erase(cur);

		output.push_back(cur);

		for (int i = 0; i < sz(inNodes[cur]); ++i) {
			int parent = inNodes[cur][i];
			if ((--outDegree[parent]) == 0)
				zeros.insert(parent);
		}
	}

}

int main() {

	scanf("%d%d", &n, &m);
	rep(i,m) {
		int p, num, ch;
		scanf("%d%d", &p, &num);
		while (num--) {
			scanf("%d", &ch);
			outNodes[p].push_back(ch);
			inNodes[ch].push_back(p);
		}
	}

	topologicalSort();

	char* sp = "";
	rep(i,sz(output)) {
		printf("%s%d", sp, output[i]);
		sp = " ";
	}

	return 0;
}
