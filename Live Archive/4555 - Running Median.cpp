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

int arr[10002];

int median(int sz) {
	sort(arr, arr + sz);
	return arr[sz / 2];
}

int main() {

	int tst;
	scanf("%d", &tst);
	//char* str = "";
	foe(t,1,tst) {
		//printf("%s", str), str = "\n";
		int n;
		scanf("%d%d", &n, &n);
		printf("%d %d\n", t, (n + 1) / 2);

		int ans = 0;
		for (int i = 0; i < n;) {
			scanf("%d", arr + (i++));
			if (i % 2) {
				printf("%d", median(i));
				ans++;
				if (n - i >= 2) {
					if (ans % 10)
						printf(" ");
					else
						printf("\n");
				}
			}
		}

		printf("\n");

	}

	return 0;
}
