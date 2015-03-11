#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>
#include <cmath>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

void find_lis(vector<int> &a, vector<int> &b) {
	vector<int> p(a.size());
	int u, v;

	if (a.empty())
		return;

	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++) {
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

		for (u = 0, v = b.size() - 1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i])
				u = c + 1;
			else
				v = c;
		}

		if (u > 0)
			p[i] = b[u - 1];
		b[u] = i;
	}

	for (u = b.size(), v = b.back(); u--; v = p[v])
		b[u] = v;
}

int main() {

	int n;
	vector<int> nums;
	while(scanf("%d",&n)!=-1)
		nums.push_back(n);

	vector<int> sol;
	find_lis(nums,sol);
	int sz = sol.size();
	printf("%d\n-\n",sz);
	fo(i,sz)
		printf("%d\n",nums[sol[i]]);
	return 0;

}
