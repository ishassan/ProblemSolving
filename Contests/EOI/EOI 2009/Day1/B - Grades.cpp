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
#include <queue>
#include <set>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int arr[1001][1001];
int col[1001];

int main() {

	int n, m;
	cin >> n >> m;
	fo(i,n)
		fo(j,m)
			cin >> arr[i][j];

	fo(j,m) {
		fo(i,n)
			col[i] = arr[i][j];
		sort(col, col + n);
		cout << col[0] << " " << col[n - 1] << endl;
	}

	return 0;
}
