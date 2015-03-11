#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)

string arr[102];
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
*/
	int n, m;
	scanf("%d%d", &n, &m);

	fo(i,n)
		cin >> arr[i];

	fo(i,n-1) {
		if (arr[i][0] == arr[i + 1][0]) {
			printf("NO\n");
			return 0;
		}
		foo(j,1,m) {
			if (arr[i][j] != arr[i][j - 1]) {
				printf("NO\n");
				return 0;
			}
		}
	}

	foo(j,1,m) {
		if (arr[n - 1][j] != arr[n - 1][j - 1]) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;

}
