#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int st[401][401];
int graph[401][401];
int rgraph[401][401];
int n;

void rotate90(int src[401][401], int dest[401][401]) {
	fo(i,n)
		fo(j,n)
			dest[j][n - i - 1] = src[i][j];
}

double calc(int g[401][401]) {
	int res = 0;
	fo(i,n)
		fo(j,n)
			if (abs(g[i][j] - st[i][j]) < 101)
				res++;

	return (double) res / (n * n);
}

void print(int arr[401][401]) {
	fo(i,n) {
		fo(j,n)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
int main() {

	while (cin >> n) {
		fo(i,n)
			fo(j,n)
				scanf("%d", &st[i][j]);

		fo(i,n)
			fo(j,n)
				scanf("%d", &graph[i][j]);

		double res = -1;
		int lim = 2;
		while (lim--) {
			rotate90(graph, rgraph);
			res = max(res, calc(rgraph));
			rotate90(rgraph, graph);
			res = max(res, calc(graph));
		}

		fo(i,n)
			reverse(graph[i], graph[i] + n);

		lim = 2;
		while (lim--) {
			rotate90(graph, rgraph);
			res = max(res, calc(rgraph));
			rotate90(rgraph, graph);
			res = max(res, calc(graph));
		}

		printf("%.2lf\n", res * 100);
	}
	return 0;
}
