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

int n;
int graph[30][30];
int in[30], out[30];
int diff[30];
bool vis[30][30];

void DFS(int idx) {

	rep(i,26)
		if (graph[idx][i] && !vis[idx][i]) {
			vis[idx][i] = 1;
			DFS(i);
		}
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		mem(graph,0);
		mem(in,0), mem(out,0), mem(diff,0);
		mem(vis,0);

		scanf("%d", &n);
		char str[1003];

		rep(i,n) {
			scanf("%s", str);
			int l = strlen(str);
			graph[str[0] - 'a'][str[l - 1] - 'a']++;
			++out[str[0] - 'a'], ++in[str[l - 1] - 'a'];
		}

		bool valid = 1;
		int pos1 = 0, neg1 = 0;
		int start = 0;
		rep(i,26) {
			diff[i] = out[i] - in[i];
			if (diff[i] > 1 || diff[i] < -1) {
				valid = 0;
				break;
			}
			if (diff[i] == 1)
				++pos1, start = i;
			else if (diff[i] == -1)
				++neg1;
		}
		if (!valid || pos1 ^ neg1 || pos1 > 1) {
			printf("The door cannot be opened.\n");
			continue;
		}

		DFS(start);
		valid = 1;
		rep(i,26)
			rep(j,26)
				if (graph[i][j] && !vis[i][j]) {
					valid = 0;
					break;
				}

		if (!valid)
			printf("The door cannot be opened.\n");
		else
			printf("Ordering is possible.\n");

	}
	return 0;
}
