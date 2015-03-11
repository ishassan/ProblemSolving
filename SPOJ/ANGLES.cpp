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

const int MAX = 91000, MIN = 302;

char graph[MIN][MIN];
int rowtable[MIN][MIN], coltable[MIN][MIN];
vector<int> adjlst[MAX];
int r, c;

void rightdown(int row, int col) {

	int plus = 0;
	for (int i = col + 1; i <= c; i++) {

		if (graph[row][i] == 'A')
			plus++;
		if (graph[row][i] == 'D')
			continue;

		adjlst[row].push_back(i+r);
		adjlst[i + r].push_back(row);
	}

	for (int i = row + 1; i <= r; i++) {
		if (graph[i][col] == 'A')
			break;
		if (graph[i][col] == 'D')
			continue;

		adjlst[i].push_back(col+r);
		adjlst[col + r].push_back(i);
	}

}

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
	for (int i = 1; i < N; i++)
		if (man[i] == -1) {
			memset(visited, 0, sizeof visited);
			if (match(i))
				cnt++;
		}
	return cnt;
}

int main() {
	//freopen("in.txt","r",stdin);
	int tst;
	scanf("%d", &tst);
	while (tst--) {
		memset(graph, 0, sizeof graph);
		memset(rowtable, 0, sizeof rowtable);
		memset(coltable, 0, sizeof coltable);

		fo(i,MAX)
			adjlst[i].clear();

		scanf("%d%d", &r, &c);


		int rid = 1;
		foe(i,1,r) {
			foe(j,1,c) {
				scanf(" %c", &graph[i][j]);
				if (graph[i][j] == 'A')
					rid++, rowtable[i][j] = 1e9;
				else if (graph[i][j] == 'H')
					rowtable[i][j] = rid;
			}
			rid++;
		}

		int cid = 45302;
		foe(j,1,c) {
			foe(i,1,r) {
				if (graph[i][j] == 'A')
					cid++, coltable[i][j] = 1e9;
				else if (graph[i][j] == 'H')
					coltable[i][j] = cid;
			}
			cid++;
		}

		N = rid;
		foe(i,1,r)
			foe(j,1,c)
				if (rowtable[i][j] < 1e9 && coltable[i][j] < 1e9)
					adjlst[rowtable[i][j]].push_back(coltable[i][j]);


		printf("%d\n", maxMatch());
	}

	return 0;
}
