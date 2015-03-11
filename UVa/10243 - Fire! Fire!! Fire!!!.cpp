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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
typedef long long ll;
using namespace std;

const int MAX = 1005;
vector<vector<int> > adjlst;
int N, man[MAX];
int M, woman[MAX];
bool visited[MAX];

bool match(int manIndex) {
	for (int i = 0; i < adjlst[manIndex].size(); i++) {
		int curwoman = adjlst[manIndex][i];
		if (visited[curwoman])
			continue;
		visited[curwoman] = true;
		if (woman[curwoman] == -1 || match(woman[curwoman])) {
			man[manIndex] = curwoman;
			woman[curwoman] = manIndex;
			return true;
		}
	}
	return false;
}
int maxMatch() {
	int cnt = 0;
	memset(man, -1, sizeof man);
	memset(woman, -1, sizeof woman);
	for (int i = 1; i <= N; i++)
		if (man[i] == -1) {
			memset(visited, 0, sizeof visited);
			if (match(i))
				cnt++;
		}
	return cnt;
}

int main() {

	int n;
	while (scanf("%d", &n) != -1 && n) {
		if (n == 1) {
			scanf("%d",&n);
			printf("1\n");
			continue;
		}

		N = n;
		adjlst.clear();
		adjlst.resize(N + 5);

		foe(i,1,n) {
			int num, num2;
			scanf("%d", &num);
			while (num--) {
				scanf("%d", &num2);
				adjlst[i].push_back(num2);
			}
		}

		printf("%d\n", (maxMatch()+1)/ 2);

	}

	return 0;
}
